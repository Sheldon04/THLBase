webpackJsonp([1],{"/Lrv":function(e,t){},"1wco":function(e,t,a){e.exports=a.p+"static/img/mfimg_2.a8e851b.png"},"327N":function(e,t){},"9ieu":function(e,t,a){e.exports=a.p+"static/img/index_img1.0695f61.jpeg"},"9luE":function(e,t){},APe1:function(e,t){},GjLa:function(e,t){},"J+Pb":function(e,t){},J3O8:function(e,t,a){e.exports=a.p+"static/img/index_img2.9814b6c.jpeg"},JQ90:function(e,t){},Mm1h:function(e,t){},NHnr:function(e,t,a){"use strict";Object.defineProperty(t,"__esModule",{value:!0});var s=a("7+uW"),l={name:"App",data:function(){return{activeIndex:this.$route.path}},methods:{handleSelect:function(e,t){console.log(e,t),this.$router.push(e)}}},n={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",{attrs:{id:"app"}},[a("el-container",[a("el-header",[a("el-menu",{staticClass:"my-el-menu",attrs:{"default-active":e.activeIndex,mode:"horizontal","background-color":"#545c64","text-color":"#fff","active-text-color":"#ffd04b"},on:{select:e.handleSelect}},[a("el-menu-item",{staticClass:"submenu-title",attrs:{index:"/index"}},[e._v("Home")]),e._v(" "),a("el-submenu",{attrs:{index:"2"}},[a("template",{slot:"title"},[a("span",{staticClass:"submenu-title"},[e._v("\n                Search\n              ")])]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1"}},[e._v("miRNA")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search2"}},[e._v("miRNA-Other")])],2),e._v(" "),a("el-menu-item",{staticClass:"submenu-title",attrs:{index:"/diffexp"}},[e._v("Differential Expression")]),e._v(" "),a("el-menu-item",{staticClass:"submenu-title",attrs:{index:"/targets"}},[e._v("miRNA Targets")]),e._v(" "),a("el-menu-item",{staticClass:"submenu-title",attrs:{index:"/enrichment"}},[e._v("Enrichment Analysis")]),e._v(" "),a("el-menu-item",{staticClass:"submenu-title",attrs:{index:"/about"}},[e._v("About")])],1)],1),e._v(" "),a("el-main",[a("router-view")],1)],1)],1)},staticRenderFns:[]};var i=a("VU/8")(l,n,!1,function(e){a("W9bH")},null,null).exports,r=a("/ocq"),o=a("9ieu"),c=a.n(o),_=a("J3O8"),u=a.n(_),d={name:"Index",data:function(){return{imgs:[c.a,u.a],activeName:"1"}}},p={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"webicon"},[e._v("\n    THLBase 1.0\n  ")]),e._v(" "),a("div",{staticClass:"intro"},[a("el-collapse",{attrs:{accordion:""},model:{value:e.activeName,callback:function(t){e.activeName=t},expression:"activeName"}},[a("el-collapse-item",{staticClass:"step",attrs:{title:"Introduction",name:"1"}},[a("div",[e._v("This project aims to build "),a("b",[e._v("a sequencing database for miRNA studies in cows")]),e._v(" (Chinese Holstein\n          cattle). The main functions include: miRNA query and literature aggregation results presentation, miRNA\n          corresponding to other non-coding RNAs query, miRNA expression level query, new miRNA prediction, miRNA\n          group differential expression comparative analysis and results download, miRNA target prediction and RNA\n          regulatory network analysis. This database can help researchers better search for differentially expressed\n          RNAs related to heat stress and heat tolerance, help researchers understand the interaction network between\n          RNAs, fill the gap of current domestic and international RNA databases of dairy cows, and play a guiding\n          role in production practice.\n        ")])]),e._v(" "),a("el-collapse-item",{staticClass:"step",attrs:{title:"Features",name:"2"}},[a("ul",[a("li",[e._v("Linked miRNA database to Microsoft Academic and other academic websites to realize real-time update of\n            search results corresponding to literature.\n          ")]),e._v(" "),a("li",[e._v(" An RNA database based on cow transcriptome sequencing data has been established to fill the gap in this\n            type of database.\n          ")]),e._v(" "),a("li",[e._v("Integrate data from multiple databases, display the results completely, and realize data visualization\n            at the same time.\n          ")])])]),e._v(" "),a("el-collapse-item",{staticClass:"step",attrs:{title:"How to use",name:"3"}},[a("div",[e._v("你猜")])]),e._v(" "),a("el-collapse-item",{staticClass:"step",attrs:{title:"How to cite",name:"4"}},[a("div",[e._v("你猜")])])],1)],1),e._v(" "),a("div",{staticClass:"block"},[a("el-carousel",{attrs:{height:"600px"}},e._l(e.imgs,function(e){return a("el-carousel-item",{key:e,staticClass:"el-carousel__item"},[a("img",{staticClass:"carousel-image",attrs:{src:e}})])}),1)],1)])},staticRenderFns:[]};var m=a("VU/8")(d,p,!1,function(e){a("327N")},null,null).exports,v={name:"Expression",data:function(){return{tableData:[],loading:!0,state:"",timeout:null,currentPage:1,total:0,pageSize:10,input:""}},methods:{handleSizeChange:function(e){console.log("每页 "+e+" 条"),this.currentPage=1,this.pageSize=e},handleCurrentChange:function(e){console.log("当前页: "+e),this.currentPage=e},handleSearch:function(){var e=this,t="findRNAByNameOrSeq?keyWord="+this.input;console.log(t),this.$http.get("http://172.26.188.102:8989/mirna/"+t).then(function(t){e.tableData=t.data,e.total=t.data.size})},handleClick:function(e){this.$router.push({path:"/search1/details",query:{id:e.miR_index}})},filterHandler:function(e,t,a){return t[a.property]===e}},created:function(){var e=this;this.$http.get("http://172.26.188.102:8989/mirna/findAll").then(function(t){e.tableData=t.data,e.total=t.data.size,e.loading=!1})}},h={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"input"},[a("el-input",{attrs:{placeholder:"Enter miRNA Name or Sequence","prefix-icon":"el-icon-search"},model:{value:e.input,callback:function(t){e.input=t},expression:"input"}})],1),e._v(" "),a("el-button",{staticClass:"search_icon",attrs:{slot:"append",icon:"el-icon-search"},on:{click:e.handleSearch},slot:"append"}),e._v(" "),a("div",{staticClass:"table"},[[a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData.slice((e.currentPage-1)*e.pageSize,e.currentPage*e.pageSize)}},[a("el-table-column",{attrs:{prop:"miR_index",label:"ID",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"miR_name",label:"RNA Name",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"miR_seq",label:"Sequence",width:"280"}}),e._v(" "),a("el-table-column",{attrs:{prop:"expression_level",label:"Expression Level",filters:[{text:"high",value:"high"},{text:"middle",value:"middle"},{text:"low",value:"low"}],"filter-method":e.filterHandler,width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"type",label:"Type",filters:[{text:"5'",value:"5'"},{text:"3'",value:"3'"}],"filter-method":e.filterHandler,width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"dg",label:"Free Energy",sortable:!0,width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"more",label:"Details",width:"180"},scopedSlots:e._u([{key:"default",fn:function(t){return[a("el-button",{attrs:{type:"text",size:"small"},on:{click:function(a){return e.handleClick(t.row)}}},[e._v("More")])]}}])})],1),e._v(" "),a("el-pagination",{attrs:{align:"center","current-page":e.currentPage,"page-sizes":[10,20,50,100],"page-size":e.pageSize,layout:"total, sizes, prev, pager, next, jumper",total:e.tableData.length},on:{"size-change":e.handleSizeChange,"current-change":e.handleCurrentChange}})]],2)],1)},staticRenderFns:[]};var f=a("VU/8")(v,h,!1,function(e){a("UQUY")},"data-v-50d52100",null).exports,g=a("mvHQ"),b=a.n(g),x={name:"ExpDetails",data:function(){return{activeIndex:this.$route.path,tableData1:[],tableData2:[],tableData3:[],tableData4:[],tableData5:[],tableData6:[],tableData7:[],tableData8:[],loading:!0,id:"",miR_name:""}},methods:{handleSelect:function(e,t){console.log(e,t),this.$router.push({path:e,query:{id:this.$route.query.id,name:this.miR_name}})}},created:function(){var e=this,t="?id="+this.$route.query.id;console.log(t),this.$http.get("http://172.26.188.102:8989/mirna/findRNADetails"+t).then(function(t){e.miR_name=t.data.miR_name;var a=b()(t.data,["sum11_r","sum12_r","sum13_r","sum14_r","sum15_r"]);e.tableData1.push(JSON.parse(a));var s=b()(t.data,["sum21_r","sum22_r","sum23_r","sum24_r","sum25_r"]);e.tableData2.push(JSON.parse(s));var l=b()(t.data,["spr11_r","spr12_r","spr13_r","spr14_r","spr15_r"]);e.tableData3.push(JSON.parse(l));var n=b()(t.data,["spr31_r","spr32_r","spr33_r","spr34_r","spr35_r"]);e.tableData4.push(JSON.parse(n));var i=b()(t.data,["sum11_n","sum12_n","sum13_n","sum14_n","sum15_n"]);e.tableData5.push(JSON.parse(i));var r=b()(t.data,["sum21_n","sum22_n","sum23_n","sum24_n","sum25_n"]);e.tableData6.push(JSON.parse(r));var o=b()(t.data,["spr11_n","spr12_n","spr13_n","spr14_n","spr15_n"]);e.tableData7.push(JSON.parse(o));var c=b()(t.data,["spr31_n","spr32_n","spr33_n","spr34_n","spr35_n"]);e.tableData8.push(JSON.parse(c)),e.loading=!1})}},w={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"navBar"},[a("el-menu",{staticClass:"el-menu-vertical-demo",attrs:{"default-active":e.activeIndex,"background-color":"#545c64","text-color":"#fff","active-text-color":"#ffd04b"},on:{select:e.handleSelect}},[a("el-submenu",{attrs:{index:"1"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-data-analysis"}),e._v(" "),a("span",[e._v("Expression")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Expression")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details"}},[e._v("Expression Level")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/mydiffexp"}},[e._v("Differential Expression")])],2),e._v(" "),a("el-menu-item-group",{attrs:{title:"Statistical Charts"}},[a("el-menu-item",{attrs:{index:"/search1/details/charts"}},[e._v("Charts")])],1)],2),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/aggregation"}},[a("i",{staticClass:"el-icon-search"}),e._v(" "),a("span",{attrs:{slot:"title"},slot:"title"},[e._v("Data Aggregation")])]),e._v(" "),a("el-submenu",{attrs:{index:"/search1/details/reference/list"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-document"}),e._v(" "),a("span",[e._v("Reference")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Reference")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/list"}},[e._v("Related List")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/statistics"}},[e._v("Correlation Statistics")])],2)],2)],1)],1),e._v(" "),a("div",{staticClass:"introduction"},[a("el-tag",{attrs:{type:"info"}},[e._v("Name")]),e._v(" "),a("el-link",e._b({staticClass:"attr",attrs:{type:"success"}},"el-link",e.miR_name,!1),[e._v(e._s(e.miR_name))]),e._v(" "),a("br"),a("br"),e._v(" "),a("el-tag",{attrs:{type:"info"}},[e._v("Note")]),e._v(" "),e._m(0)],1),e._v(" "),a("div",{staticClass:"details"},[[a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData1}},[a("el-table-column",{attrs:{prop:"sum11_r",label:"Sum11(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum12_r",label:"Sum12(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum13_r",label:"Sum13(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum14_r",label:"Sum14(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum15_r",label:"Sum15(raw)",width:"180"}})],1),e._v(" "),a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData2}},[a("el-table-column",{attrs:{prop:"sum21_r",label:"Sum21(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum22_r",label:"Sum22(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum23_r",label:"Sum23(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum24_r",label:"Sum24(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum25_r",label:"Sum25(raw)",width:"180"}})],1),e._v(" "),a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData3}},[a("el-table-column",{attrs:{prop:"spr11_r",label:"Spr11(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr12_r",label:"Spr12(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr13_r",label:"Spr13(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr14_r",label:"Spr14(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr15_r",label:"Spr15(raw)",width:"180"}})],1),e._v(" "),a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData4}},[a("el-table-column",{attrs:{prop:"spr31_r",label:"Spr31(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr32_r",label:"Spr32(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr33_r",label:"Spr33(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr34_r",label:"Spr34(raw)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr35_r",label:"Spr35(raw)",width:"180"}})],1),e._v(" "),a("br"),a("br"),e._v(" "),a("el-divider"),e._v(" "),a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData5}},[a("el-table-column",{attrs:{prop:"sum11_n",label:"Sum11(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum12_n",label:"Sum12(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum13_n",label:"Sum13(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum14_n",label:"Sum14(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum15_n",label:"Sum15(norm)",width:"180"}})],1),e._v(" "),a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData6}},[a("el-table-column",{attrs:{prop:"sum21_n",label:"Sum21(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum22_n",label:"Sum22(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum23_n",label:"Sum23(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum24_n",label:"Sum24(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"sum25_n",label:"Sum25(norm)",width:"180"}})],1),e._v(" "),a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData7}},[a("el-table-column",{attrs:{prop:"spr11_n",label:"Spr11(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr12_n",label:"Spr12(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr13_n",label:"Spr13(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr14_n",label:"Spr14(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr15_n",label:"Spr15(norm)",width:"180"}})],1),e._v(" "),a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData8}},[a("el-table-column",{attrs:{prop:"spr31_n",label:"Spr31(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr32_n",label:"Spr32(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr33_n",label:"Spr33(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr34_n",label:"Spr34(norm)",width:"180"}}),e._v(" "),a("el-table-column",{attrs:{prop:"spr35_n",label:"Spr35(norm)",width:"180"}})],1)]],2)])},staticRenderFns:[function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("ul",{staticClass:"note"},[a("li",[e._v("The research material is the serum of five cows in summer and five cows in spring.")]),e._v(" "),a("li",[e._v("For the two groups of samples ("),a("b",[e._v("Sum1 vs Spr3")]),e._v(")，the location is the same but the seasons are different.")]),e._v(" "),a("li",[e._v("For the two groups of samples ("),a("b",[e._v("Sum1/Spr1 vs Sum2/Spr3")]),e._v(")，the season is the same but the locations are different.")])])}]};var S=a("VU/8")(x,w,!1,function(e){a("QUD5")},"data-v-110c1015",null).exports,C={render:function(){var e=this.$createElement;return(this._self._c||e)("div",[this._v("\n  enrich\n")])},staticRenderFns:[]};var R=a("VU/8")({name:"Others"},C,!1,function(e){a("QyDy")},"data-v-a4db1080",null).exports,y={render:function(){var e=this.$createElement;return(this._self._c||e)("div",[this._v("\n  enrich\n")])},staticRenderFns:[]};var D=a("VU/8")({name:"Enrichment"},y,!1,function(e){a("Mm1h")},"data-v-07970736",null).exports,N={render:function(){var e=this.$createElement;return(this._self._c||e)("div",[this._v("\n  enrich\n")])},staticRenderFns:[]};var E=a("VU/8")({name:"Targets"},N,!1,function(e){a("JQ90")},"data-v-61202d30",null).exports,A={render:function(){var e=this.$createElement;return(this._self._c||e)("h1",[this._v("\n  田森茂，洪纲忆，李海涛\n")])},staticRenderFns:[]};var $=a("VU/8")({name:"About"},A,!1,function(e){a("cgYU")},"data-v-0f9acb64",null).exports,z={render:function(){var e=this.$createElement;return(this._self._c||e)("div",[this._v("\n  hello\n")])},staticRenderFns:[]};var F=a("VU/8")({name:"DiffExp"},z,!1,function(e){a("/Lrv")},"data-v-671c0c39",null).exports,q={name:"Aggregation",data:function(){return{activeIndex:this.$route.path}},methods:{handleSelect:function(e,t){console.log(e,t),this.$router.push({path:e,query:{id:this.$route.query.id}})}}},k={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"navBar"},[a("el-menu",{staticClass:"el-menu-vertical-demo",attrs:{"default-active":e.activeIndex,"default-openeds":e.defalut,"background-color":"#545c64","text-color":"#fff","active-text-color":"#ffd04b"},on:{select:e.handleSelect}},[a("el-submenu",{attrs:{index:"1"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-data-analysis"}),e._v(" "),a("span",[e._v("Expression")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Expression")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details"}},[e._v("Expression Level")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/mydiffexp"}},[e._v("Differential Expression")])],2),e._v(" "),a("el-menu-item-group",{attrs:{title:"Statistical Charts"}},[a("el-menu-item",{attrs:{index:"/search1/details/charts"}},[e._v("Charts")])],1)],2),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/aggregation"}},[a("i",{staticClass:"el-icon-search"}),e._v(" "),a("span",{attrs:{slot:"title"},slot:"title"},[e._v("Data Aggregation")])]),e._v(" "),a("el-submenu",{attrs:{index:"/search1/details/reference/list"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-document"}),e._v(" "),a("span",[e._v("Reference")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Reference")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/list"}},[e._v("Related List")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/statistics"}},[e._v("Correlation Statistics")])],2)],2)],1)],1)])},staticRenderFns:[]};var U=a("VU/8")(q,k,!1,function(e){a("GjLa")},"data-v-41926769",null).exports,I={name:"Charts",data:function(){return{activeIndex:this.$route.path}},methods:{handleSelect:function(e,t){console.log(e,t),this.$router.push({path:e,query:{id:this.$route.query.id}})}}},L={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"navBar"},[a("el-menu",{staticClass:"el-menu-vertical-demo",attrs:{"default-active":e.activeIndex,"default-openeds":e.defalut,"background-color":"#545c64","text-color":"#fff","active-text-color":"#ffd04b"},on:{select:e.handleSelect}},[a("el-submenu",{attrs:{index:"1"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-data-analysis"}),e._v(" "),a("span",[e._v("Expression")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Expression")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details"}},[e._v("Expression Level")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/mydiffexp"}},[e._v("Differential Expression")])],2),e._v(" "),a("el-menu-item-group",{attrs:{title:"Statistical Charts"}},[a("el-menu-item",{attrs:{index:"/search1/details/charts"}},[e._v("Charts")])],1)],2),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/aggregation"}},[a("i",{staticClass:"el-icon-search"}),e._v(" "),a("span",{attrs:{slot:"title"},slot:"title"},[e._v("Data Aggregation")])]),e._v(" "),a("el-submenu",{attrs:{index:"/search1/details/reference/list"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-document"}),e._v(" "),a("span",[e._v("Reference")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Reference")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/list"}},[e._v("Related List")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/statistics"}},[e._v("Correlation Statistics")])],2)],2)],1)],1)])},staticRenderFns:[]};var P=a("VU/8")(I,L,!1,function(e){a("m93z")},"data-v-37b706db",null).exports,O={name:"MyDiffExp",data:function(){return{activeIndex:this.$route.path,miR_name:"",up_down_1:"",fc_1:"",log2_fc_1:"",p_value_1:"",up_down_2:"",fc_2:"",log2_fc_2:"",p_value_2:"",up_down_3:"",fc_3:"",log2_fc_3:"",p_value_3:"",up_down_4:"",fc_4:"",log2_fc_4:"",p_value_4:""}},methods:{handleSelect:function(e,t){console.log(e,t),this.$router.push({path:e,query:{id:this.$route.query.id}})}},created:function(){var e=this,t="?miR_name="+this.$route.query.name;this.$http.get("http://172.26.188.102:8989/mirna/findDiffExpA"+t).then(function(t){e.miR_name=t.data.miR_name;var a=b()(t.data,["up_down","fold_change","log2_fold_change","p_value"]),s=JSON.parse(a);e.up_down_1=s.up_down,e.fc_1=s.fold_change,e.log2_fc_1=s.log2_fold_change,e.p_value_1=s.p_value}),this.$http.get("http://172.26.188.102:8989/mirna/findDiffExpB"+t).then(function(t){e.miR_name=t.data.miR_name;var a=b()(t.data,["up_down","fold_change","log2_fold_change","p_value"]),s=JSON.parse(a);e.up_down_2=s.up_down,e.fc_2=s.fold_change,e.log2_fc_2=s.log2_fold_change,e.p_value_2=s.p_value}),this.$http.get("http://172.26.188.102:8989/mirna/findDiffExpC"+t).then(function(t){e.miR_name=t.data.miR_name;var a=b()(t.data,["up_down","fold_change","log2_fold_change","p_value"]),s=JSON.parse(a);e.up_down_3=s.up_down,e.fc_3=s.fold_change,e.log2_fc_3=s.log2_fold_change,e.p_value_3=s.p_value}),this.$http.get("http://172.26.188.102:8989/mirna/findDiffExpD"+t).then(function(t){e.miR_name=t.data.miR_name;var a=b()(t.data,["up_down","fold_change","log2_fold_change","p_value"]),s=JSON.parse(a);e.up_down_4=s.up_down,e.fc_4=s.fold_change,e.log2_fc_4=s.log2_fold_change,e.p_value_4=s.p_value})}},J={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"navBar"},[a("el-menu",{staticClass:"el-menu-vertical-demo",attrs:{"default-active":e.activeIndex,"default-openeds":e.defalut,"background-color":"#545c64","text-color":"#fff","active-text-color":"#ffd04b"},on:{select:e.handleSelect}},[a("el-submenu",{attrs:{index:"1"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-data-analysis"}),e._v(" "),a("span",[e._v("Expression")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Expression")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details"}},[e._v("Expression Level")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/mydiffexp"}},[e._v("Differential Expression")])],2),e._v(" "),a("el-menu-item-group",{attrs:{title:"Statistical Charts"}},[a("el-menu-item",{attrs:{index:"/search1/details/charts"}},[e._v("Charts")])],1)],2),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/aggregation"}},[a("i",{staticClass:"el-icon-search"}),e._v(" "),a("span",{attrs:{slot:"title"},slot:"title"},[e._v("Data Aggregation")])]),e._v(" "),a("el-submenu",{attrs:{index:"/search1/details/reference/list"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-document"}),e._v(" "),a("span",[e._v("Reference")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Reference")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/list"}},[e._v("Related List")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/statistics"}},[e._v("Correlation Statistics")])],2)],2)],1)],1),e._v(" "),a("div",{staticClass:"introduction"},[a("el-tag",{attrs:{type:"info"}},[e._v("Name")]),e._v(" "),a("el-link",e._b({staticClass:"attr",attrs:{type:"success"}},"el-link",e.miR_name,!1),[e._v(e._s(e.miR_name))]),e._v(" "),a("br"),a("br"),e._v(" "),a("el-tag",{attrs:{type:"info"}},[e._v("Note")]),e._v(" "),e._m(0)],1),e._v(" "),a("el-card",{staticClass:"box-card-1"},[a("div",{staticClass:"clearfix",attrs:{slot:"header"},slot:"header"},[a("span",[e._v("Spr3 vs Spr1")])]),e._v(" "),a("div",{staticClass:"text item"},[a("ul",[a("li",e._b({},"li",e.up_down_1,!1),[a("span",[e._v("Up/Down: ")]),e._v(e._s(e.up_down_1))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.fc_1,!1),[a("span",[e._v("Fold Change: ")]),e._v(e._s(e.fc_1))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.log2_fc_1,!1),[a("span",[e._v("Fold Change(log2): ")]),e._v(e._s(e.log2_fc_1))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.p_value_1,!1),[a("span",[e._v("P-Value(T-test): ")]),e._v(e._s(e.p_value_1))]),e._v(" "),a("br")])])]),e._v(" "),a("el-card",{staticClass:"box-card-2"},[a("div",{staticClass:"clearfix",attrs:{slot:"header"},slot:"header"},[a("span",[e._v("Spr3 vs Spr1")])]),e._v(" "),a("div",{staticClass:"text item"},[a("ul",[a("li",e._b({},"li",e.up_down_2,!1),[a("span",[e._v("Up/Down: ")]),e._v(e._s(e.up_down_2))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.fc_2,!1),[a("span",[e._v("Fold Change: ")]),e._v(e._s(e.fc_2))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.log2_fc_2,!1),[a("span",[e._v("Fold Change(log2): ")]),e._v(e._s(e.log2_fc_2))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.p_value_2,!1),[a("span",[e._v("P-Value(T-test): ")]),e._v(e._s(e.p_value_2))]),e._v(" "),a("br")])])]),e._v(" "),a("el-card",{staticClass:"box-card-3"},[a("div",{staticClass:"clearfix",attrs:{slot:"header"},slot:"header"},[a("span",[e._v("Spr3 vs Spr1")])]),e._v(" "),a("div",{staticClass:"text item"},[a("ul",[a("li",e._b({},"li",e.up_down_3,!1),[a("span",[e._v("Up/Down: ")]),e._v(e._s(e.up_down_3))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.fc_3,!1),[a("span",[e._v("Fold Change: ")]),e._v(e._s(e.fc_3))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.log2_fc_3,!1),[a("span",[e._v("Fold Change(log2): ")]),e._v(e._s(e.log2_fc_3))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.p_value_3,!1),[a("span",[e._v("P-Value(T-test): ")]),e._v(e._s(e.p_value_3))]),e._v(" "),a("br")])])]),e._v(" "),a("el-card",{staticClass:"box-card-4"},[a("div",{staticClass:"clearfix",attrs:{slot:"header"},slot:"header"},[a("span",[e._v("Spr3 vs Spr1")])]),e._v(" "),a("div",{staticClass:"text item"},[a("ul",[a("li",e._b({},"li",e.up_down_4,!1),[a("span",[e._v("Up/Down:  ")]),e._v(e._s(e.up_down_4))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.fc_4,!1),[a("span",[e._v("Fold Change:  ")]),e._v(e._s(e.fc_4))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.log2_fc_4,!1),[a("span",[e._v("Fold Change(log2):  ")]),e._v(e._s(e.log2_fc_4))]),e._v(" "),a("br"),e._v(" "),a("li",e._b({},"li",e.p_value_4,!1),[a("span",[e._v("P-Value(T-test):  ")]),e._v(e._s(e.p_value_4))]),e._v(" "),a("br")])])])],1)},staticRenderFns:[function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("ul",{staticClass:"note"},[a("li",[e._v("The research material is the serum of five cows in summer and five cows in spring.")]),e._v(" "),a("li",[e._v("For the two groups of samples ("),a("b",[e._v("Sum1 vs Spr3")]),e._v(")，the location is the same but the seasons are different.")]),e._v(" "),a("li",[e._v("For the two groups of samples ("),a("b",[e._v("Sum1/Spr1 vs Sum2/Spr3")]),e._v(")，the season is the same but the locations are different.")])])}]};var T=a("VU/8")(O,J,!1,function(e){a("J+Pb")},null,null).exports,V=a("c/rQ"),H=a.n(V),B=a("1wco"),Q=a.n(B),W={name:"RefList",data:function(){return{activeIndex:this.$route.path,miR_name:"",Img1:H.a,Img2:Q.a,currentPage:1,pageSize:10,tableData:[],loading:!0}},methods:{handleSelect:function(e,t){console.log(e,t),this.$router.push({path:e,query:{id:this.$route.query.id}})},handleSizeChange:function(e){console.log("每页 "+e+" 条"),this.currentPage=1,this.pageSize=e},handleCurrentChange:function(e){console.log("当前页: "+e),this.currentPage=e}},created:function(){var e=this;this.miR_name=this.$route.query.name;var t,a="https://api.labs.cognitive.microsoft.com/academic/v1.0/evaluate?expr=And(And(AW=%27"+(t=this.miR_name.toLowerCase().split("-"))[0]+"%27,AW=%27"+t[1]+"%27),AW=%27"+t[2]+"%27)&model=latest&count=100&offset=0&attributes=Ti,AW,AA.AuN,Y,CC,DOI&subscription-key=4f2ddbedc9ae48638b0e969e988b48ec";this.$http.get(a).then(function(t){console.log(t.data),e.tableData=t.data.entities,e.loading=!1})}},j={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"navBar"},[a("el-menu",{staticClass:"el-menu-vertical-demo",attrs:{"default-active":e.activeIndex,"background-color":"#545c64","text-color":"#fff","active-text-color":"#ffd04b"},on:{select:e.handleSelect}},[a("el-submenu",{attrs:{index:"1"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-data-analysis"}),e._v(" "),a("span",[e._v("Expression")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Expression")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details"}},[e._v("Expression Level")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/mydiffexp"}},[e._v("Differential Expression")])],2),e._v(" "),a("el-menu-item-group",{attrs:{title:"Statistical Charts"}},[a("el-menu-item",{attrs:{index:"/search1/details/charts"}},[e._v("Charts")])],1)],2),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/aggregation"}},[a("i",{staticClass:"el-icon-search"}),e._v(" "),a("span",{attrs:{slot:"title"},slot:"title"},[e._v("Data Aggregation")])]),e._v(" "),a("el-submenu",{attrs:{index:"/search1/details/reference/list"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-document"}),e._v(" "),a("span",[e._v("Reference")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Reference")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/list"}},[e._v("Related List")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/statistics"}},[e._v("Correlation Statistics")])],2)],2)],1)],1),e._v(" "),a("div",{staticClass:"table"},[[a("el-table",{directives:[{name:"loading",rawName:"v-loading",value:e.loading,expression:"loading"}],staticStyle:{width:"100%"},attrs:{data:e.tableData.slice((e.currentPage-1)*e.pageSize,e.currentPage*e.pageSize)}},[a("el-table-column",{attrs:{prop:"logprob",label:"Prob",width:"80"}}),e._v(" "),a("el-table-column",{attrs:{prop:"Ti",label:"Title",width:"280"}}),e._v(" "),a("el-table-column",{attrs:{prop:"AA.0.AuN",label:"Author",width:"120"}}),e._v(" "),a("el-table-column",{attrs:{prop:"Y",label:"Year",sortable:!0,width:"100"}}),e._v(" "),a("el-table-column",{attrs:{prop:"CC",label:"Citations",sortable:!0,width:"120"}}),e._v(" "),a("el-table-column",{attrs:{prop:"DOI",label:"DOI",width:"220"}})],1),e._v(" "),a("el-pagination",{attrs:{align:"center","current-page":e.currentPage,"page-sizes":[5,10,20],"page-size":e.pageSize,layout:"total, sizes, prev, pager, next, jumper",total:e.tableData.length},on:{"size-change":e.handleSizeChange,"current-change":e.handleCurrentChange}})]],2),e._v(" "),a("div",[a("img",{staticClass:"img2",attrs:{src:e.Img2}}),e._v(" "),a("img",{staticClass:"img1",attrs:{src:e.Img1}})])])},staticRenderFns:[]};var M=a("VU/8")(W,j,!1,function(e){a("APe1")},"data-v-5dc043b6",null).exports,Y={name:"RefStatistic",data:function(){return{activeIndex:this.$route.path}},methods:{handleSelect:function(e,t){console.log(e,t),this.$router.push({path:e,query:{id:this.$route.query.id}})}}},G={render:function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("div",[a("div",{staticClass:"navBar"},[a("el-menu",{staticClass:"el-menu-vertical-demo",attrs:{"default-active":e.activeIndex,"default-openeds":e.defalut,"background-color":"#545c64","text-color":"#fff","active-text-color":"#ffd04b"},on:{select:e.handleSelect}},[a("el-submenu",{attrs:{index:"1"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-data-analysis"}),e._v(" "),a("span",[e._v("Expression")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Expression")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details"}},[e._v("Expression Level")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/mydiffexp"}},[e._v("Differential Expression")])],2),e._v(" "),a("el-menu-item-group",{attrs:{title:"Statistical Charts"}},[a("el-menu-item",{attrs:{index:"/search1/details/charts"}},[e._v("Charts")])],1)],2),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/aggregation"}},[a("i",{staticClass:"el-icon-search"}),e._v(" "),a("span",{attrs:{slot:"title"},slot:"title"},[e._v("Data Aggregation")])]),e._v(" "),a("el-submenu",{attrs:{index:"/search1/details/reference/list"}},[a("template",{slot:"title"},[a("i",{staticClass:"el-icon-document"}),e._v(" "),a("span",[e._v("Reference")])]),e._v(" "),a("el-menu-item-group",[a("template",{slot:"title"},[e._v("Reference")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/list"}},[e._v("Related List")]),e._v(" "),a("el-menu-item",{attrs:{index:"/search1/details/reference/statistics"}},[e._v("Correlation Statistics")])],2)],2)],1)],1)])},staticRenderFns:[]};var K=a("VU/8")(Y,G,!1,function(e){a("9luE")},"data-v-4f63ebe5",null).exports;s.default.use(r.a);var X=new r.a({routes:[{path:"/",redirect:"/index",meta:{title:"THLBase"}},{path:"/index",component:m,meta:{title:"THLBase"}},{path:"/search1",component:f},{path:"/search2",component:R},{path:"/targets",component:E},{path:"/enrichment",component:D},{path:"/about",component:$},{path:"/search1/details",component:S},{path:"/diffexp",component:F},{path:"/search1/details/mydiffexp",component:T},{path:"/search1/details/charts",component:P},{path:"/search1/details/reference/list",component:M},{path:"/search1/details/reference/statistics",component:K},{path:"/search1/details/aggregation",component:U}]}),Z=a("zL8q"),ee=a.n(Z),te=(a("tvR6"),a("mtWM")),ae=a.n(te);s.default.use(ee.a),s.default.prototype.$http=ae.a,s.default.config.productionTip=!1,new s.default({el:"#app",router:X,components:{App:i},template:"<App/>"})},QUD5:function(e,t){},QyDy:function(e,t){},UQUY:function(e,t){},W9bH:function(e,t){},"c/rQ":function(e,t,a){e.exports=a.p+"static/img/mfimg_1.456080c.png"},cgYU:function(e,t){},m93z:function(e,t){},tvR6:function(e,t){}},["NHnr"]);
//# sourceMappingURL=app.73e9123db1be3e296c4c.js.map