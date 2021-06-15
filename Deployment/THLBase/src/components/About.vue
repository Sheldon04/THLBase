<template>
  <dev>
    <el-card class="box-card-1">
      <div slot="header" class="clearfix">
        <div class="centerText">About Us</div>
      </div>
      <div class="text item">
        <ul>
          <li class="centerText">Author: 田森茂 洪纲忆 李海涛</li>
          <br>
          <li class="centerText">CopyRight: 2021-2025</li>
        </ul>
      </div>
    </el-card>
  </dev>
</template>

<script>
export default {
  name: 'About'
}
</script>

<style scoped>
.box-card-1{
  position: absolute;
  top: 100px;
  left: 100px;
  width: 400px;
  height: 200px;
}
.centerText{
  text-align:center;
}

</style>
