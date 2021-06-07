<template>
  <div>
    <div class="webicon">
      THLBase 1.0
    </div>
    <div class="intro">
      <el-collapse v-model="activeName" accordion>
        <el-collapse-item title="Introduction" name="1" class="step">
          <div>This project aims to build <b>a sequencing database for miRNA studies in cows</b> (Chinese Holstein cattle). The main functions include: miRNA query and literature aggregation results presentation, miRNA corresponding to other non-coding RNAs query, miRNA expression level query, new miRNA prediction, miRNA group differential expression comparative analysis and results download, miRNA target prediction and RNA regulatory network analysis. This database can help researchers better search for differentially expressed RNAs related to heat stress and heat tolerance, help researchers understand the interaction network between RNAs, fill the gap of current domestic and international RNA databases of dairy cows, and play a guiding role in production practice.</div>
        </el-collapse-item>
        <el-collapse-item title="Features" name="2" class="step">
          <ul>
            <li>Linked miRNA database to Microsoft Academic and other academic websites to realize real-time update of search results corresponding to literature.</li>
            <li> An RNA database based on cow transcriptome sequencing data has been established to fill the gap in this type of database.</li>
            <li>Integrate data from multiple databases, display the results completely, and realize data visualization at the same time.</li>
          </ul>
        </el-collapse-item>
        <el-collapse-item title="How to use" name="3" class="step">
          <div>你猜</div>
        </el-collapse-item>
        <el-collapse-item title="How to cite" name="4" class="step">
          <div>你猜</div>
        </el-collapse-item>
      </el-collapse>
    </div>
    <div class="block">
      <el-carousel height="400px">
        <el-carousel-item v-for="item in imgs" :key="item">
          <el-image
            style="height: 400px"
            :src="item"
            fit="contain"></el-image>
        </el-carousel-item>
      </el-carousel>
    </div>
  </div>
</template>

<script>
import indexImg1 from '../assets/index_img1.jpeg'
import indexImg2 from '../assets/index_img2.jpeg'
export default {
  name: 'Index',
  data () {
    return {
      imgs: [indexImg1, indexImg2],
      activeName: '1'
    }
  }
}
</script>

<style>
.block{
  height: 600px;
  width:600px;
  position: absolute;
  left:750px;
  top: 150px;
}
.webicon{
  font-family: 'Trebuchet';
  font-size: 50px;
  position: absolute;
  left: 180px;
  top: 100px;
}
.intro{
  width:600px;
  position: absolute;
  left:50px;
  top: 200px;
}
.el-collapse-item__header, el-collapse-item__header is-active{
  font-size: 20px !important;
}

</style>
