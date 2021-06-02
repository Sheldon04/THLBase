package com.thlserver.dao;

import com.thlserver.entity.*;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface RNADao {
    List<MicroRNA> findAll();
    List<MicroRNA> findRNAByNameOrSeq(@Param("keyword") String keyWord);
}
