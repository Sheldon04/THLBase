package com.thlserver.service;

import com.thlserver.entity.MicroRNA;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface RNAService {
    List<MicroRNA> findAll();

    List<MicroRNA> findRNAByNameOrSeq(String keyWord);

    MicroRNA findRNADetails(String id);

    MicroRNA findDiffExp(String miR_name, String group);
}
