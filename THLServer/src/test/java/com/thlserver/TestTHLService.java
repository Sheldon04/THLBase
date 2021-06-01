package com.thlserver;

import com.thlserver.service.RNAService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class TestTHLService {
    @Autowired
    private RNAService rnaService;

    @Test
    public void testFindAll(){
        rnaService.findAll().forEach(RNA->System.out.println("RNA = " + RNA));
    }
}
