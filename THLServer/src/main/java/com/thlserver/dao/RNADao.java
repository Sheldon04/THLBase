package com.thlserver.dao;

import com.thlserver.entity.*;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface RNADao {
    List<MicroRNA> findAll();
    List<MicroRNA> findRNAByNameOrSeq(@Param("keyword") String keyWord);
    MicroRNA findRNADetails(@Param("index") String id);
    MicroRNA findDiffExpA(@Param("mirName") String miR_name);
    MicroRNA findDiffExpB(@Param("mirName") String miR_name);
    MicroRNA findDiffExpC(@Param("mirName") String miR_name);
    MicroRNA findDiffExpD(@Param("mirName") String miR_name);
}
