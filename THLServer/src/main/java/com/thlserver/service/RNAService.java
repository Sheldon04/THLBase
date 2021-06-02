package com.thlserver.service;

import com.thlserver.entity.MicroRNA;

import java.util.List;

public interface RNAService {
    List<MicroRNA> findAll();
    List<MicroRNA> findRNAByNameOrSeq(String keyWord);
}
