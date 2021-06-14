<template>
  <div>
    <div class="navBar">
      <el-menu
        :default-active="activeIndex"
        class="el-menu-vertical-demo"
        @select="handleSelect"
        background-color="#545c64"
        text-color="#fff"
        active-text-color="#ffd04b">
        <el-submenu index="1">
          <template slot="title">
            <i class="el-icon-data-analysis"></i>
            <span>Expression</span>
          </template>
          <el-menu-item-group>
            <template slot="title">Expression</template>
            <el-menu-item index="/search1/details">Expression Level</el-menu-item>
            <el-menu-item index="/search1/details/mydiffexp">Differential Expression</el-menu-item>
          </el-menu-item-group>
          <el-menu-item-group title="Statistical Charts">
            <el-menu-item index="/search1/details/charts">Charts</el-menu-item>
          </el-menu-item-group>
        </el-submenu>
        <el-menu-item index="/search1/details/aggregation">
          <i class="el-icon-search"></i>
          <span slot="title">Data Aggregation</span>
        </el-menu-item>
        <el-submenu index="/search1/details/reference/list">
          <template slot="title">
            <i class="el-icon-document"></i>
            <span>Reference</span>
          </template>
          <el-menu-item-group>
            <template slot="title">Reference</template>
            <el-menu-item index="/search1/details/reference/list">Related List</el-menu-item>
            <el-menu-item index="/search1/details/reference/statistics">Correlation Statistics</el-menu-item>
          </el-menu-item-group>
        </el-submenu>
      </el-menu>
    </div>
    <div class="table">
      <template>
        <el-table
          v-loading="loading"
          :data="tableData.slice((currentPage-1)*pageSize,currentPage*pageSize)"
          style="width: 100%">
          <el-table-column
            prop="logprob"
            label="Prob"
            width="80">
          </el-table-column>
          <el-table-column
            prop="Ti"
            label="Title"
            width="280">
          </el-table-column>
          <el-table-column
            prop="AA.0.AuN"
            label="Author"
            width="120">
          </el-table-column>
          <el-table-column
            prop="Y"
            label="Year"
            :sortable="true"
            width="100">
          </el-table-column>
          <el-table-column
            prop="CC"
            label="Citations"
            :sortable="true"
            width="120">
          </el-table-column>
          <el-table-column
            prop="DOI"
            label="DOI"
            width="220">
          </el-table-column>
        </el-table>
        <el-pagination align='center' @size-change="handleSizeChange" @current-change="handleCurrentChange"
                       :current-page="currentPage"
                       :page-sizes="[5,10,20]"
                       :page-size="pageSize"
                       layout="total, sizes, prev, pager, next, jumper"
                       :total="tableData.length">
        </el-pagination>
      </template>
    </div>
    <div>
      <img class="img2" :src="Img2"/>
      <img class="img1" :src="Img1"/>
    </div>
  </div>
</template>

<script>
import indexImg1 from '../../../assets/mfimg_1.png'
import indexImg2 from '../../../assets/mfimg_2.png'

export default {
  name: 'RefList',
  data () {
    return {
      activeIndex: this.$route.path,
      miR_name: '',
      Img1: indexImg1,
      Img2: indexImg2,
      currentPage: 1, // 当前页码
      pageSize: 10,
      tableData: [],
      loading: true
    }
  },
  methods: {
    handleSelect (key, keyPath) {
      console.log(key, keyPath)
      this.$router.push({
        path: key,
        query: {
          id: this.$route.query.id,
          name: this.$route.query.name
        }
      })
    },
    handleSizeChange (val) {
      console.log(`每页 ${val} 条`)
      this.currentPage = 1
      this.pageSize = val
    },
    handleCurrentChange (val) {
      console.log(`当前页: ${val}`)
      this.currentPage = val
    }
  },
  created () {
    this.miR_name = this.$route.query.name
    let name = this.miR_name.toLowerCase()
    var words = []
    words = name.split('-')
    let queryWord = 'https://api.labs.cognitive.microsoft.com/academic/v1.0/evaluate?expr=And(And(AW=%27' + words[0] + '%27,AW=%27' + words[1] + '%27),AW=%27' + words[2] + '%27)&model=latest&count=100&offset=0&attributes=Ti,AW,AA.AuN,Y,CC,DOI&subscription-key=4f2ddbedc9ae48638b0e969e988b48ec'
    this.$http.get(queryWord).then(res => {
      console.log(res.data)
      this.tableData = res.data['entities']
      this.loading = false
    })
  }
}
</script>

<style scoped>
.img1{
  position: absolute;
  right: 20px;
  top: 200px;
  width: 200px;
  height: 400px;
}
.img2{
  position: absolute;
  right: 20px;
  top: 100px;
  width: 200px;
  height: 50px;
}

.navBar {
  width: 250px;
  position: absolute;
}

.table {
  position: absolute;
  width: 1000px !important;
  top: 100px !important;
  left: 300px !important;
}
</style>
