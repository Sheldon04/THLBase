<template>
  <div class="table">
    <template>
      <el-table
        :data="tableData"
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
            <a href="/index.html">More</a>
          </template>
        </el-table-column>
      </el-table>
    </template>
  </div>
</template>

<script>
export default {
  name: 'Expression',
  data () {
    return {
      tableData: [],
      state: '',
      timeout: null
    }
  },
  created () {
    this.$http.get('http://localhost:8989/mirna/findAll').then(res => {
      this.tableData = res.data
      console.log(res.data)
    })
  }
}
</script>

<style scoped>

</style>
