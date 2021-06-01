package com.thlserver.service;

import com.thlserver.dao.RNADao;
import com.thlserver.entity.MicroRNA;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional
public class RNAServiceImpl implements RNAService{
    private RNADao rnaDao;

    @Autowired
    public void setUserDao (RNADao rnaDao) {
        this.rnaDao = rnaDao;
    }
    @Override
    public List<MicroRNA> findAll() {
        return rnaDao.findAll();
    }
}
