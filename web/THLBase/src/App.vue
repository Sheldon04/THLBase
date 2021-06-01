<template>
  <div id="app">
    <el-container>
      <el-header>
        <el-menu
          :default-active="activeIndex"
          class="my-el-menu"
          mode="horizontal"
          @select="handleSelect"
          background-color="#545c64"
          text-color="#fff"
          active-text-color="#ffd04b">
          <el-menu-item index="/index" class="submenu-title">Home</el-menu-item>
          <el-submenu index="2">
            <template slot="title">
                <span class="submenu-title">
                  Search
                </span>
            </template>
            <el-menu-item index="/search1">Expression Level</el-menu-item>
            <el-menu-item index="/search2">All miRNAs</el-menu-item>
            <el-menu-item index="/search3">miRNA-Other</el-menu-item>
          </el-submenu>
          <el-menu-item index="/targets" class="submenu-title">miRNA Targets</el-menu-item>
          <el-menu-item index="/enrichment" class="submenu-title">Enrichment Analysis</el-menu-item>
          <el-menu-item index="/about" class="submenu-title">About</el-menu-item>
        </el-menu>
      </el-header>
      <el-main>
        <router-view/>
      </el-main>
    </el-container>
  </div>
</template>

<script>
export default {
  name: 'App',
  data () {
    return {
      activeIndex: '/index'
    }
  },
  methods: {
    handleSelect (key, keyPath) {
      console.log(key, keyPath)
      this.$router.push(key)
    }
  }
}
</script>

<style>
#app {
}
.submenu-title{
  font-family: "Trebuchet";
  font-size: 18px;
}
</style>
