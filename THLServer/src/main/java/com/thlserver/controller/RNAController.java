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

    @GetMapping("findDiffExpA")
    public MicroRNA findDiffExpA(String miR_name) {
        return rnaService.findDiffExpA(miR_name);
    }

    @GetMapping("findDiffExpB")
    public MicroRNA findDiffExpB(String miR_name) {
        return rnaService.findDiffExpB(miR_name);
    }

    @GetMapping("findDiffExpC")
    public MicroRNA findDiffExpC(String miR_name) {
        return rnaService.findDiffExpC(miR_name);
    }

    @GetMapping("findDiffExpD")
    public MicroRNA findDiffExpD(String miR_name) {
        return rnaService.findDiffExpD(miR_name);
    }

    @GetMapping("findDiffExpTotal")
    public List<MicroRNA> findDiffExpTotal() {
        return rnaService.findDiffExpTotal();
    }

    @GetMapping("findIdByName")
    public List<String> findIdByName(String miR_name){
        return rnaService.findIdByName(miR_name);
    }

}
