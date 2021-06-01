import Vue from 'vue'
import Router from 'vue-router'
import Index from '../components/Index.vue'
import Expression from '../components/search/Expression.vue'
import LinkRNA from '../components/search/LinkRNA.vue'
import Others from '../components/search/Others.vue'
import Enrichment from '../components/enrichment/Enrichment.vue'
import Targets from '../components/targets/Targets.vue'
import About from '../components/About'
Vue.use(Router)

var router = new Router({
  routes: [
    {
      path: '/',
      redirect: '/index',
      meta: {
        title: 'THLBase'
      }
    },
    {
      path: '/index',
      component: Index,
      meta: {
        title: 'THLBase'
      }
    },
    {
      path: '/search1',
      component: Expression
    },
    {
      path: '/search2',
      component: LinkRNA
    },
    {
      path: '/search3',
      component: Others
    },
    {
      path: '/targets',
      component: Targets
    },
    {
      path: '/enrichment',
      component: Enrichment
    },
    {
      path: '/about',
      component: About
    }
  ]
})
export default router
