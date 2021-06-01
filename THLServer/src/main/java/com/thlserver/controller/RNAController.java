package com.thlserver.controller;

import com.thlserver.entity.MicroRNA;
import com.thlserver.service.RNAService;
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
    public List<MicroRNA> findAll(){
        return rnaService.findAll();
    }
}
