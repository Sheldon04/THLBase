import Vue from 'vue'
import Router from 'vue-router'
import Index from '../components/Index.vue'
import Expression from '../components/search/Expression.vue'
import ExpDetails from '../components/search/expdetails/ExpDetails'
import Others from '../components/search/Others.vue'
import Enrichment from '../components/enrichment/Enrichment.vue'
import Targets from '../components/targets/Targets.vue'
import About from '../components/About'
import DiffExp from '../components/diffexp/DiffExp'
import Aggregation from '../components/search/expdetails/Aggregation'
import Charts from '../components/search/expdetails/Charts'
import MyDiffExp from '../components/search/expdetails/MyDiffExp'
import RefList from '../components/search/expdetails/RefList'
import RefStatistic from '../components/search/expdetails/RefStatistic'
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
    },
    {
      path: '/search1/details',
      component: ExpDetails
    },
    {
      path: '/diffexp',
      component: DiffExp
    },
    {
      path: '/search1/details/mydiffexp',
      component: MyDiffExp
    },
    {
      path: '/search1/details/charts',
      component: Charts
    },
    {
      path: '/search1/details/reference/list',
      component: RefList
    },
    {
      path: '/search1/details/reference/statistics',
      component: RefStatistic
    },
    {
      path: '/search1/details/aggregation',
      component: Aggregation
    }
  ]
})

const originalPush = Router.prototype.push
Router.prototype.push = function push (location) {
  return originalPush.call(this, location).catch(err => err)
}

export default router
