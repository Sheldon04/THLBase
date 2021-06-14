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
  </div>
</template>

<script>
export default {
  name: 'Charts',
  data () {
    return {
      activeIndex: this.$route.path
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
  }
}
</script>

<style scoped>

.navBar {
  width: 250px;
  position: absolute;
}

</style>
