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
    <div class="introduction">
      <el-tag type="info">Name</el-tag>
      <el-link type="success" v-bind="miR_name" class="attr">{{miR_name}}</el-link>
      <br><br>
      <el-tag type="info">Note</el-tag>
      <ul class="note">
        <li>The research material is the serum of five cows in summer and five cows in spring.</li>
        <li>For the two groups of samples (<b>Sum1 vs Spr3</b>)，the location is the same but the seasons are different.</li>
        <li>For the two groups of samples (<b>Sum1/Spr1 vs Sum2/Spr3</b>)，the season is the same but the locations are different.</li>
      </ul>
    </div>
    <div class="details">
      <template>
        <el-table
          v-loading="loading"
          :data="tableData1"
          style="width: 100%">
          <el-table-column
            prop="sum11_r"
            label="Sum11(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum12_r"
            label="Sum12(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum13_r"
            label="Sum13(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum14_r"
            label="Sum14(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum15_r"
            label="Sum15(raw)"
            width="180">
          </el-table-column>
        </el-table>
        <el-table
          v-loading="loading"
          :data="tableData2"
          style="width: 100%">
          <el-table-column
            prop="sum21_r"
            label="Sum21(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum22_r"
            label="Sum22(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum23_r"
            label="Sum23(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum24_r"
            label="Sum24(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum25_r"
            label="Sum25(raw)"
            width="180">
          </el-table-column>
        </el-table>
        <el-table
          v-loading="loading"
          :data="tableData3"
          style="width: 100%">
          <el-table-column
            prop="spr11_r"
            label="Spr11(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr12_r"
            label="Spr12(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr13_r"
            label="Spr13(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr14_r"
            label="Spr14(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr15_r"
            label="Spr15(raw)"
            width="180">
          </el-table-column>
        </el-table>
        <el-table
          v-loading="loading"
          :data="tableData4"
          style="width: 100%">
          <el-table-column
            prop="spr31_r"
            label="Spr31(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr32_r"
            label="Spr32(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr33_r"
            label="Spr33(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr34_r"
            label="Spr34(raw)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr35_r"
            label="Spr35(raw)"
            width="180">
          </el-table-column>
        </el-table>
        <!--
        --------------------
        --------------------
        -->
        <br><br>
        <el-divider></el-divider>
        <el-table
          v-loading="loading"
          :data="tableData5"
          style="width: 100%">
          <el-table-column
            prop="sum11_n"
            label="Sum11(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum12_n"
            label="Sum12(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum13_n"
            label="Sum13(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum14_n"
            label="Sum14(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum15_n"
            label="Sum15(norm)"
            width="180">
          </el-table-column>
        </el-table>
        <el-table
          v-loading="loading"
          :data="tableData6"
          style="width: 100%">
          <el-table-column
            prop="sum21_n"
            label="Sum21(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum22_n"
            label="Sum22(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum23_n"
            label="Sum23(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum24_n"
            label="Sum24(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="sum25_n"
            label="Sum25(norm)"
            width="180">
          </el-table-column>
        </el-table>
        <el-table
          v-loading="loading"
          :data="tableData7"
          style="width: 100%">
          <el-table-column
            prop="spr11_n"
            label="Spr11(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr12_n"
            label="Spr12(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr13_n"
            label="Spr13(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr14_n"
            label="Spr14(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr15_n"
            label="Spr15(norm)"
            width="180">
          </el-table-column>
        </el-table>
        <el-table
          v-loading="loading"
          :data="tableData8"
          style="width: 100%">
          <el-table-column
            prop="spr31_n"
            label="Spr31(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr32_n"
            label="Spr32(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr33_n"
            label="Spr33(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr34_n"
            label="Spr34(norm)"
            width="180">
          </el-table-column>
          <el-table-column
            prop="spr35_n"
            label="Spr35(norm)"
            width="180">
          </el-table-column>
        </el-table>
      </template>
    </div>
  </div>
</template>

<script>
export default {
  name: 'ExpDetails',
  data () {
    return {
      activeIndex: this.$route.path,
      tableData1: [],
      tableData2: [],
      tableData3: [],
      tableData4: [],
      tableData5: [],
      tableData6: [],
      tableData7: [],
      tableData8: [],
      loading: true,
      id: '',
      miR_name: ''
    }
  },
  methods: {
    handleSelect (key, keyPath) {
      console.log(key, keyPath)
      this.$router.push({
        path: key,
        query: {
          id: this.$route.query.id,
          name: this.miR_name
        }
      })
    }
  },
  created () {
    var keyWord = '?id=' + this.$route.query.id
    console.log(keyWord)
    this.$http.get('http://47.106.148.74:8989/mirna/findRNADetails' + keyWord).then(res => {
      this.miR_name = res.data['miR_name']
      var s1 = JSON.stringify(res.data, ['sum11_r', 'sum12_r', 'sum13_r', 'sum14_r', 'sum15_r'])
      this.tableData1.push(JSON.parse(s1))
      var s2 = JSON.stringify(res.data, ['sum21_r', 'sum22_r', 'sum23_r', 'sum24_r', 'sum25_r'])
      this.tableData2.push(JSON.parse(s2))
      var s3 = JSON.stringify(res.data, ['spr11_r', 'spr12_r', 'spr13_r', 'spr14_r', 'spr15_r'])
      this.tableData3.push(JSON.parse(s3))
      var s4 = JSON.stringify(res.data, ['spr31_r', 'spr32_r', 'spr33_r', 'spr34_r', 'spr35_r'])
      this.tableData4.push(JSON.parse(s4))
      var s5 = JSON.stringify(res.data, ['sum11_n', 'sum12_n', 'sum13_n', 'sum14_n', 'sum15_n'])
      this.tableData5.push(JSON.parse(s5))
      var s6 = JSON.stringify(res.data, ['sum21_n', 'sum22_n', 'sum23_n', 'sum24_n', 'sum25_n'])
      this.tableData6.push(JSON.parse(s6))
      var s7 = JSON.stringify(res.data, ['spr11_n', 'spr12_n', 'spr13_n', 'spr14_n', 'spr15_n'])
      this.tableData7.push(JSON.parse(s7))
      var s8 = JSON.stringify(res.data, ['spr31_n', 'spr32_n', 'spr33_n', 'spr34_n', 'spr35_n'])
      this.tableData8.push(JSON.parse(s8))
      this.loading = false
    })
  }
}
</script>

<style scoped>
.details {
  position: absolute;
  left: 400px;
  top: 300px;
}

.navBar {
  width: 250px;
  position: absolute;
}

.introduction {
  position: absolute;
  width: 800px;
  top: 100px;
  left: 400px;
  font-family: "Times New Roman" !important;
}
.note{
  position: absolute;
  top: 40px;
  left: 40px;
  font-size: 18px;
}
.attr{
  font-family: "Times New Roman" !important;
  font-size: 30px !important;
  left: 20px !important;
}
</style>
