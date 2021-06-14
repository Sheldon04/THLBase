package com.thlserver.service;

import com.thlserver.entity.MicroRNA;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface RNAService {
    List<MicroRNA> findAll();

    List<MicroRNA> findRNAByNameOrSeq(String keyWord);

    MicroRNA findRNADetails(String id);

    MicroRNA findDiffExpA(String miR_name);
    MicroRNA findDiffExpB(String miR_name);
    MicroRNA findDiffExpC(String miR_name);
    MicroRNA findDiffExpD(String miR_name);
    List<MicroRNA> findDiffExpTotal();
    List<String> findIdByName(String miR_name);


}
