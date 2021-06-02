<template>
  <div>
  <div class="input">
    <el-input placeholder="Enter miRNA Name or Sequence" v-model="input" prefix-icon="el-icon-search"></el-input>
  </div>
    <el-button slot="append" icon="el-icon-search" class="search_icon" @click="handleSearch"></el-button>
  <div class="table">
    <template>
      <el-table
        :data="tableData.slice((currentPage-1)*pageSize,currentPage*pageSize)"
        style="width: 100%">
        <el-table-column
          prop="miR_index"
          label="ID"
          width="180">
        </el-table-column>
        <el-table-column
          prop="miR_name"
          label="RNA Name"
          width="180">
        </el-table-column>
        <el-table-column
          prop="miR_seq"
          label="Sequence"
          width="280">
        </el-table-column>
        <el-table-column
          prop="expression_level"
          label="Expression Level"
          width="180">
        </el-table-column>
        <el-table-column
          prop="type"
          label="Type"
          width="180">
        </el-table-column>
        <el-table-column
          prop="dg"
          label="Free Energy"
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
  name: 'Expression',
  data () {
    return {
      tableData: [],
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
      this.$http.get('http://localhost:8989/mirna/' + keyWord).then(res => {
        this.tableData = res.data
        this.total = res.data.size
      })
    },
    handleClick (row)
    {
      this.$router.push({path:'/search1/details',params:{}})
    }
  },
  created () {
    this.$http.get('http://localhost:8989/mirna/findAll').then(res => {
      this.tableData = res.data
      this.total = res.data.size
    })
  }
}
</script>

<style>
.input{
  width: 300px;
}
.search_icon{
  position: absolute;
  top: 88px;
  left: 350px;
}
</style>
