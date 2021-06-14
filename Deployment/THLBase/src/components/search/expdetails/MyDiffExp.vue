<template>
  <div>
    <div class="navBar">
      <el-menu
        :default-active="activeIndex"
        class="el-menu-vertical-demo"
        :default-openeds="defalut"
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
    <el-card class="box-card-1">
      <div slot="header" class="clearfix">
        <span>Spr3 vs Spr1</span>
      </div>
      <div class="text item">
        <ul>
          <li v-bind="up_down_1"><span>Up/Down: </span>{{up_down_1}}</li>
          <br>
          <li v-bind="fc_1"><span>Fold Change: </span>{{fc_1}}</li>
          <br>
          <li v-bind="log2_fc_1"><span>Fold Change(log2): </span>{{log2_fc_1}}</li>
          <br>
          <li v-bind="p_value_1"><span>P-Value(T-test): </span>{{p_value_1}}</li>
          <br>
        </ul>
      </div>
    </el-card>
    <el-card class="box-card-2">
      <div slot="header" class="clearfix">
        <span>Spr3 vs Spr1</span>
      </div>
      <div class="text item">
        <ul>
          <li v-bind="up_down_2"><span>Up/Down: </span>{{up_down_2}}</li>
          <br>
          <li v-bind="fc_2"><span>Fold Change: </span>{{fc_2}}</li>
          <br>
          <li v-bind="log2_fc_2"><span>Fold Change(log2): </span>{{log2_fc_2}}</li>
          <br>
          <li v-bind="p_value_2"><span>P-Value(T-test): </span>{{p_value_2}}</li>
          <br>
        </ul>
      </div>
    </el-card>
    <el-card class="box-card-3">
      <div slot="header" class="clearfix">
        <span>Spr3 vs Spr1</span>
      </div>
      <div class="text item">
        <ul>
          <li v-bind="up_down_3"><span>Up/Down: </span>{{up_down_3}}</li>
          <br>
          <li v-bind="fc_3"><span>Fold Change: </span>{{fc_3}}</li>
          <br>
          <li v-bind="log2_fc_3"><span>Fold Change(log2): </span>{{log2_fc_3}}</li>
          <br>
          <li v-bind="p_value_3"><span>P-Value(T-test): </span>{{p_value_3}}</li>
          <br>
        </ul>
      </div>
    </el-card>
    <el-card class="box-card-4">
      <div slot="header" class="clearfix">
        <span>Spr3 vs Spr1</span>
      </div>
      <div class="text item">
        <ul>
          <li v-bind="up_down_4"><span>Up/Down:  </span>{{up_down_4}}</li>
          <br>
          <li v-bind="fc_4"><span>Fold Change:  </span>{{fc_4}}</li>
          <br>
          <li v-bind="log2_fc_4"><span>Fold Change(log2):  </span>{{log2_fc_4}}</li>
          <br>
          <li v-bind="p_value_4"><span>P-Value(T-test):  </span>{{p_value_4}}</li>
          <br>
        </ul>
      </div>
    </el-card>
  </div>
</template>

<script>
export default {
  name: 'MyDiffExp',
  data () {
    return {
      activeIndex: this.$route.path,
      miR_name: '',
      up_down_1: '',
      fc_1: '',
      log2_fc_1: '',
      p_value_1: '',
      up_down_2: '',
      fc_2: '',
      log2_fc_2: '',
      p_value_2: '',
      up_down_3: '',
      fc_3: '',
      log2_fc_3: '',
      p_value_3: '',
      up_down_4: '',
      fc_4: '',
      log2_fc_4: '',
      p_value_4: ''
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
    }
  },
  created () {
    var keyWord = '?miR_name=' + this.$route.query.name
    this.$http.get('http://47.106.148.74:8989/mirna/findDiffExpA' + keyWord).then(res => {
      this.miR_name = res.data['miR_name']
      let s1 = JSON.stringify(res.data, ['up_down', 'fold_change', 'log2_fold_change', 'p_value'])
      let json1 = JSON.parse(s1)
      this.up_down_1 = json1['up_down']
      this.fc_1 = json1['fold_change']
      this.log2_fc_1 = json1['log2_fold_change']
      this.p_value_1 = json1['p_value']
    })

    this.$http.get('http://47.106.148.74:8989/mirna/findDiffExpB' + keyWord).then(res => {
      this.miR_name = res.data['miR_name']
      let s1 = JSON.stringify(res.data, ['up_down', 'fold_change', 'log2_fold_change', 'p_value'])
      let json1 = JSON.parse(s1)
      this.up_down_2 = json1['up_down']
      this.fc_2 = json1['fold_change']
      this.log2_fc_2 = json1['log2_fold_change']
      this.p_value_2 = json1['p_value']
    })

    this.$http.get('http://47.106.148.74:8989/mirna/findDiffExpC' + keyWord).then(res => {
      this.miR_name = res.data['miR_name']
      let s1 = JSON.stringify(res.data, ['up_down', 'fold_change', 'log2_fold_change', 'p_value'])
      let json1 = JSON.parse(s1)
      this.up_down_3 = json1['up_down']
      this.fc_3 = json1['fold_change']
      this.log2_fc_3 = json1['log2_fold_change']
      this.p_value_3 = json1['p_value']
    })

    this.$http.get('http://47.106.148.74:8989/mirna/findDiffExpD' + keyWord).then(res => {
      this.miR_name = res.data['miR_name']
      let s1 = JSON.stringify(res.data, ['up_down', 'fold_change', 'log2_fold_change', 'p_value'])
      let json1 = JSON.parse(s1)
      this.up_down_4 = json1['up_down']
      this.fc_4 = json1['fold_change']
      this.log2_fc_4 = json1['log2_fold_change']
      this.p_value_4 = json1['p_value']
    })
  }
}
</script>

<style>
.box-card-1{
  position: absolute;
  top: 350px;
  left: 400px;
  width: 400px;
}
.box-card-2{
  position: absolute;
  top: 350px;
  left: 850px;
  width: 400px;
}
.box-card-3{
  position: absolute;
  top: 700px;
  left: 400px;
  width: 400px;
}
.box-card-4{
  position: absolute;
  top: 700px;
  left: 850px;
  width: 400px;
}

.navBar {
  width: 250px;
  position: absolute;
}

.note{
  position: absolute;
  top: 40px;
  left: 40px;
  font-size: 18px;
}

.introduction {
  position: absolute;
  width: 800px;
  top: 100px;
  left: 400px;
  font-family: "Times New Roman" !important;
}

.attr{
  font-family: "Times New Roman" !important;
  font-size: 30px !important;
  left: 20px !important;
}

</style>
