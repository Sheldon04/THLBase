package com.thlserver.controller;

import com.thlserver.entity.MicroRNA;
import com.thlserver.service.RNAService;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@CrossOrigin
@RestController
@RequestMapping("mirna")
public class RNAController {
    @Autowired
    private RNAService rnaService;

    @GetMapping("findAll")
    public List<MicroRNA> findAll() {
        return rnaService.findAll();
    }

    @GetMapping("findRNAByNameOrSeq")
    public List<MicroRNA> findRNAByNameOrSeq(String keyWord) {
        return rnaService.findRNAByNameOrSeq(keyWord);
    }

    @GetMapping("findRNADetails")
    public MicroRNA findRNADetails(String id) {
        return rnaService.findRNADetails(id);
    }

    @GetMapping("findDiffExp")
    public MicroRNA findDiffExp(String miR_name, String group) {
        return rnaService.findDiffExp(miR_name, group);
    }

}
