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
          <li v-bind="up_down_4"><span>Up/Down: </span>{{up_down_4}}</li>
          <br>
          <li v-bind="fc_4"><span>Fold Change: </span>{{fc_4}}</li>
          <br>
          <li v-bind="log2_fc_4"><span>Fold Change(log2): </span>{{log2_fc_4}}</li>
          <br>
          <li v-bind="p_value_4"><span>P-Value(T-test): </span>{{p_value_4}}</li>
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
          id: this.$route.query.id
        }
      })
    }
  }
}
</script>

<style>
.box-card-1{
  position: absolute;
  top: 100px;
  left: 400px;
  width: 400px;
}
.box-card-2{
  position: absolute;
  top: 100px;
  left: 850px;
  width: 400px;
}
.box-card-3{
  position: absolute;
  top: 450px;
  left: 400px;
  width: 400px;
}
.box-card-4{
  position: absolute;
  top: 450px;
  left: 850px;
  width: 400px;
}

.navBar {
  width: 250px;
  position: absolute;
}

</style>
