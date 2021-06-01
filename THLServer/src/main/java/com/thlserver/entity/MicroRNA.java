package com.thlserver.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ToString

public class MicroRNA {
    private String miR_index;
    private String miR_name;
    private String miR_seq;
    private String expression_level;
    private String type;
    private String dG;
}
