package com.thlserver.dao;

import com.thlserver.entity.*;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface RNADao {
    List<MicroRNA> findAll();
}
