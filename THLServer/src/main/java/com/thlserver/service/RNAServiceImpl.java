package com.thlserver.service;

import com.thlserver.dao.RNADao;
import com.thlserver.entity.MicroRNA;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional
public class RNAServiceImpl implements RNAService {
    private RNADao rnaDao;

    @Autowired(required = false)
    public void setRnaDao(RNADao rnaDao) {
        this.rnaDao = rnaDao;
    }

    @Override
    public List<MicroRNA> findAll() {
        return rnaDao.findAll();
    }

    @Override
    public List<MicroRNA> findRNAByNameOrSeq(String keyWord) {
        return rnaDao.findRNAByNameOrSeq(keyWord);
    }

    @Override
    public MicroRNA findRNADetails(String id) {
        return rnaDao.findRNADetails(id);
    }

    @Override
    public MicroRNA findDiffExpA(String miR_name) {
        return rnaDao.findDiffExpA(miR_name);
    }

    @Override
    public MicroRNA findDiffExpB(String miR_name) {
        return rnaDao.findDiffExpB(miR_name);
    }

    @Override
    public MicroRNA findDiffExpC(String miR_name) {
        return rnaDao.findDiffExpC(miR_name);
    }

    @Override
    public MicroRNA findDiffExpD(String miR_name) {
        return rnaDao.findDiffExpD(miR_name);
    }

}
