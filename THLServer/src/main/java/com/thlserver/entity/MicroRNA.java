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
    //common info
    private String miR_index;
    private String miR_name;
    private String miR_seq;
    private String expression_level;
    private String type;
    private String dG;

    /*
    miR_index, miR_name, miR_seq, rep_miRID, miRbase_seq, type, CG, dG,
    Sum11(raw), Sum12(raw), Sum13(raw), Sum14(raw), Sum15(raw), Sum21(raw), Sum22(raw),
    Sum23(raw), Sum24(raw), Sum25(raw), Spr11(raw), Spr12(raw), Spr13(raw), Spr14(raw), Spr15(raw),
    Spr31(raw), Spr32(raw), Spr33(raw), Spr34(raw), Spr35(raw), Sum11(norm), Sum12(norm), Sum13(norm),
    Sum14(norm), Sum15(norm), Sum21(norm), Sum22(norm), Sum23(norm), Sum24(norm), Sum25(norm), Spr11(norm),
    Spr12(norm), Spr13(norm), Spr14(norm), Spr15(norm), Spr31(norm), Spr32(norm), Spr33(norm), Spr34(norm),
    Spr35(norm), expression_level
     */

    //details
    private String sum11_r;
    private String sum12_r;
    private String sum13_r;
    private String sum14_r;
    private String sum15_r;
    private String sum21_r;
    private String sum22_r;
    private String sum23_r;
    private String sum24_r;
    private String sum25_r;

    private String spr11_r;
    private String spr12_r;
    private String spr13_r;
    private String spr14_r;
    private String spr15_r;
    private String spr31_r;
    private String spr32_r;
    private String spr33_r;
    private String spr34_r;
    private String spr35_r;

    private String sum11_n;
    private String sum12_n;
    private String sum13_n;
    private String sum14_n;
    private String sum15_n;
    private String sum21_n;
    private String sum22_n;
    private String sum23_n;
    private String sum24_n;
    private String sum25_n;

    private String spr11_n;
    private String spr12_n;
    private String spr13_n;
    private String spr14_n;
    private String spr15_n;
    private String spr31_n;
    private String spr32_n;
    private String spr33_n;
    private String spr34_n;
    private String spr35_n;

    //differential expression
    private String group;
    private String up_down;
    private String fold_change;
    private String log2_fold_change;
    private String p_value;

}
