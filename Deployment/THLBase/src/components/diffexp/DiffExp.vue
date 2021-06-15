<template>
  <div>
    <div class="input">
      <el-input placeholder="Enter..." v-model="input" prefix-icon="el-icon-search"></el-input>
    </div>
    <el-button slot="append" icon="el-icon-search" class="search_icon" @click="handleSearch"></el-button>
    <div class="table">
      <template>
        <el-table
          v-loading="loading"
          :data="tableData.slice((currentPage-1)*pageSize,currentPage*pageSize)"
          style="width: 100%"
          @sort-change="onSortChange">
          <el-table-column
            prop="miR_index"
            label="ID"
            width="180">
          </el-table-column>
          <el-table-column
            prop="miR_name"
            label="RNA Name"
            width="240">
          </el-table-column>
          <el-table-column
            prop="miR_seq"
            label="Sequence"
            width="280">
          </el-table-column>
          <el-table-column
            prop="p_value"
            label="pValue"
            sortable="custom"
            width="180">
          </el-table-column>
          <el-table-column
            prop="more"
            label="Details"
            width="180">
            <template slot-scope="scope">
              <el-button @click="handleClick(scope.row)" type="text" size="small">More</el-button>
            </template>
          </el-table-column>
        </el-table>
        <el-pagination align='center' @size-change="handleSizeChange" @current-change="handleCurrentChange"
                       :current-page="currentPage"
                       :page-sizes="[10,20,50,100]"
                       :page-size="pageSize"
                       layout="total, sizes, prev, pager, next, jumper"
                       :total="tableData.length">
        </el-pagination>
      </template>
    </div>
  </div>
</template>

<script>
export default {
  name: 'DiffExp',
  data () {
    return {
      info: [],
      tableData: [],
      loading: true,
      state: '',
      timeout: null,
      currentPage: 1, // 当前页码
      total: 0, // 总条数
      pageSize: 10, // 每页的数据条数
      input: ''
    }
  },
  methods: {
    handleSizeChange (val) {
      console.log(`每页 ${val} 条`)
      this.currentPage = 1
      this.pageSize = val
    },
    handleCurrentChange (val) {
      console.log(`当前页: ${val}`)
      this.currentPage = val
    },
    handleSearch () {
      var keyWord = 'findRNAByNameOrSeq?keyWord=' + this.input
      console.log(keyWord)
      this.$http.get('http://47.106.148.74:8989/mirna/' + keyWord).then(res => {
        this.tableData = res.data
        this.total = res.data.size
      })
    },
    handleClick (row) {
      console.log('http://47.106.148.74:8989/mirna/findIdByName?miR_name=' + row.miR_name)
      this.$http.get('http://47.106.148.74:8989/mirna/findIdByName?miR_name=' + row.miR_name).then(res => {
        this.info = res.data
        console.log(this.info[0])
        this.$router.push({
          path: '/search1/details/mydiffexp',
          query: {
            id: this.info[0],
            name: row.miR_name
          }
        })
      })
    },
    filterHandler (value, row, column) {
      const property = column['property']
      return row[property] === value
    },
    /**
     * 表格排序事件处理函数
     * @param {object} {column,prop,order} 列数据|排序字段|排序方式
     */
    onSortChange ({ prop, order }) {
      this.tableData.sort(this.compare(prop, order))
    },

    /**
     * 排序比较
     * @param {string} propertyName 排序的属性名
     * @param {string} sort ascending(升序)/descending(降序)
     * @return {function}
     */
    compare (propertyName, sort) {
      return function (obj1, obj2) {
        var value1 = obj1[propertyName]
        var value2 = obj2[propertyName]
        if (typeof value1 === 'string' && typeof value2 === 'string') {
          const res = value1.localeCompare(value2, 'zh')
          return sort === 'ascending' ? res : -res
        } else {
          if (value1 <= value2) {
            return sort === 'ascending' ? -1 : 1
          } else if (value1 > value2) {
            return sort === 'ascending' ? 1 : -1
          }
        }
        // return value1 < value2 ? -1 : 1
      }
    }
  },
  created () { // 从后端获取数据  起始构造属性
    this.$http.get('http://127.0.0.1:8989/mirna/findDiffExpTotal').then(res => {
      this.tableData = res.data
      this.total = res.data.size
      this.loading = false
    })
  }
}
</script>

<style>
.input {
  width: 300px;
}

.search_icon {
  position: absolute;
  top: 88px;
  left: 350px;
}

.table {
  position: absolute;
  left: 250px;
}
</style>
