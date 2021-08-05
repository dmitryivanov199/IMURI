//
// Created by apt-15 on 05.08.2021.
//

#include "CppUTest/TestHarness.h"

#include "../../source/md5/md5.h"

TEST_GROUP(Md5TestGroup) {
};

TEST(Md5TestGroup, test1) {
    std::string expected = "9dbb09647ab44eacc81d71292165166f";
    std::string actual = Md5::getMd5Hash(
            "io4jg 498h 4jhij 4hj4 h  4jh94jh9ij4jhu9by tfrD%EED6f  yj 56yjm67;m65-jm=klo ki4 ju4 unu bnbn n4hnm4m                 kkkkkkkkkkkkkkk h4ihjmi4hjmi4jh0i4jhi04jhi0j4ihj             4hj94jhj4ih 4j ihi4 ji4jhj4ui93u9gb3b2 tg fcgv2 gv 3 vb 4b 4 4bn4nu949mn mnu9 nu nnununun9nujn nun45ghn43hnn34hn43nhnuhn43j");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test2) {
    std::string expected = "f1eebcfd3f919187a925dc3f88531a2c";
    std::string actual = Md5::getMd5Hash(
            "r94h t9487 hu43h8943 h89u  3hin3ihnirekkkkkkkkkkk uhuyg54E@#!WAS@Z#XDF%VCV^TVBT^VBTVBB  HG HBBN**NB*BN*BN*BN*NB*UNB*YBYyyyyyyyyy        4u5oyhn4n  uu4u  h435gh3u8gh3h gh3gh                i35hgi3 uigh            ;43hlp4l5hok4ih 4nhu4nghbn43ghbn4ui3bhnir3hi34nhin43ihni4hn");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test3) {
    std::string expected = "7215ee9c7d9dc229d2921a40e899ec5f";
    std::string actual = Md5::getMd5Hash(" ");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test4) {
    std::string expected = "96d1b00338ca6dab10230236170fcf13";
    std::string actual = Md5::getMd5Hash(
            "uA&+RJ4D.rFlGGJfG$QDb,o/4,XE?M=$m+JC73StGU*$zmuy%-r Yt$CxJF@u5,nv/zu/FUST@_Wwtg18m\\nco^/2-Rb!4n#)M^z");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test5) {
    std::string expected = "60f643aff766e9fb89c2b8a5f83ba695";
    std::string actual = Md5::getMd5Hash("*=Yds%P_&J~6M03Zzq,CzNzIDGa_&i83wbvJT28&WK!J4,.jC ");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test6) {
    std::string expected = "c1e18f70860350f4c1ae324d018fd3f1";
    std::string actual = Md5::getMd5Hash(
            R"(-ja_TntzTvO7~lx- x lPqMmIYuwZ(d4~L.RLt.4t.t)#M yX8*n7B~U\vUfezVs qdr\*X^2OW@*2v~UJB0,4v%G8z1(1bJ!ST_~aC%znHwR%)V3!CfNtyvmi*KOF.UD=wftEifyu?5N9npy2cF*N2@fy$,r@g kwY1JbDUF?@a67NH9-SAzTnSr5viquEFXYIZqmD!R$tT$q1e59Y3l9RjSS$+do\l%%%f/$azmRTrTXXDep)TIqRb1d!zTy^kWF^cY*uQQpv)I%=Oh(SpibvNzu@ZQ )N/T7dZU5LCknx6!Nj!m#GPCSHh&?+@WNj!X8oU=5GEg(NeMc1E5pObmUDQC8T=ZRH!(Zxo!u3Um  Tsf\UkOZgesv%xV\USz%&rQjf+fW^ZiA-ZYbeyg(PjpWDv5mYUO\Ukanq80*UB6t1,Uu5.$4W&9fBd$iR*RP0kDQk30=?uK9Q97lNkO+S+K(?,eY\YP9-)0Qgfkhnu5d_cgJ=4)IRfnl_RIY7Ey.C+yKP p6B=F(&9e6$0jL H!eJUAPo@UO2KeS15Bny9W7(Rf.4fW#AuofouN?NsR$5*rp%~m%.zJF/dzk=AiT1.Udy(L(93Mfgr=x&L#Y=DOjL/$wUh1s Ry@q&\A9P$@ V?O\=thT.aa4VtaiuP7yM0W~Io-?S=4FLX7F^mJ1R!F_l5r%lq%pEXH!?@zZ9Q9HRGE/67M(bed p7FOH25gFvuxZk*r#=m,$r3+m6MZWF#T@.gs0zg0q-R%_!Z9oG~GmB,IV-V%?XQ%kNU0)K\B.Quh#Q5uh9\JAb/r$\uJffx3PV+d1A!F\KMA-j4Rx(h#/Vf~o%gCJHCV.M/EH.Pl3~i lMOMcDrj7CrDM\Ye!LubSI5b-jF?#/qJOELkQ=t6jWWx2&jAFl\QbdrIdN&\5UfR5f^sydJuW*Q(=$zQXjgCr9u36p,#-LBKCVl*Wej_izUmaVQuAnb_@B16BZ6bdIiS+Io.vB\lm+kV@0l)");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test7) {
    std::string expected = "3e25960a79dbc69b674cd4ec67a72c62";
    std::string actual = Md5::getMd5Hash("Hello world");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test8) {
    std::string expected = "6943fe3c48c5982c3a303b5872924d0e";
    std::string actual = Md5::getMd5Hash(
            "ZAld@MkigJ\\#d#nV,/\\*fx\\DSOF-m SYybtVtung/M2u#zdP^g#F9@oWZ3l9(!G%LY21wv-0HHg$y)kvdKq16xEC_2PC-@dVvc5w07&uI#oP$L#Dv5d8iW@,hwPS0#&kH~BZ )~fp-XW B5&A7T*p4le !M-m.Ud1IROd?gZ2O?~=*KL(zaII8BQBY8U=X@o6kxLPxKlYA 3)P&H&&Ouae.sVzo+9J)d!Cs@qATtbyEP&T+xg%PISyzU7VAR4PzH4GMsX_pr(cHowu8nOSTKmArNR^W+daT%SMZg7nF20YP3tuJTHg#dyqPr?BIYm,%6*v20VuTU eS+NPKSys@yb^GVY=xqqK\\0y#uH_2)pfI~)R1mP?vd\\2uYoeHe&V8JQ\\5Ci+?bmJO&R*nTorp 1wp6UN4j vOoB( /h#.zaGTaVE)QodC?U9-SuiZ9HRmcYN3u8=UNgs _9y*A@ecw3.~0pI&t?Vy26902d9b6o\\-cK8&P4XAy*$My&J!N\\7/4iW~1nPKjoj6&RIl..mnLMV$1I3ktCpt@vpj.&*&A.*M53t$-_(8uf+eRuvNm8Zi?(502P*Pi./G#fDL3yb3z8S\\hex\\HMR^&bIDayoIxRK0,)f,ss(Y!0W$Q0hDm&/f+N*vCZCpw4$XG^&xN1tT(9^A2(n==^?QIzRNqWBO*o7Q%?Oef2^Z)j6pW4R,HV+gVCmfqIMzj)/)IRJq\\lkHiSHGwAh\\lH9Jyj?&A)jI hQr6Bz+3 +s1.NfY?nSFj/\\#t9.7=7kWbt@?*S5Bo~ovnSCv-4BjK+pCgzWN,pgxsHNIj+m5L+v1/4Vxi 145j5.ViObVl!.fHWiibXmd,b^f5Z8NAy\\R^W3TrV\\rje,Qgazmn%!cRTv@c*U??l1uDn^R7@YQ6+&^Z.h-(?2(1PzLT+YetX~l/46tOnreY.sq=WdJ+NjiDc8MZ#1_+n*=NqyD)bB!_J2bfgV.*^wokS3g@..Rhw/Ll,izSji_I4ap");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test9) {
    std::string expected = "5b13c0cc62faba91fcc6dcac78ac5270";
    std::string actual = Md5::getMd5Hash(
            "Hn+?^?.QLS19MVlR^NfDwS!P3ivTX14fzT ZdCn-kgv*lobje0+c/+*GEU-.#9HrnaKypcT*qbed,zs4zbBLE\\Hr/0(mYh+@vkcMt=y_+Rpn&o4_gGAQ7rwCV8ZMi/&+=Q2k1Vcu27PWcv(Nr/A7waJ83K?GbQuu4t8~mot,iR=2$=b66pYAg3_qb%uRIEy!pLAf~&31-PnTA1.Ck&r9KDl-1VHI*?#\\2cfWkg%b9&/81l$#s?pVbE#&LIRuB/oc0gVLt,^Z42nwpfi \\ymbqG7=6swK_o&Tgo#-RnR=fTTinxQD5A086xI20xPueOf&ulC VcUHb~S^fPUPob?2-3lPIC%NNz!AFEIV?NSDWU=Bei?SOxubiPP*4x&,YQJ6eXdNygw8_4oj~VSM~TY3 WL=ofmX~xWfB 1Mw~3h&sk3=ELA.c,fB!1lu!y -$jNXHOixhC/-eO,!!=YsGf6SsJc^L1~(@J#E2)I?)jTm(MiXHqv.ZLh");
    STRCMP_EQUAL(expected.data(), actual.data())
}

TEST(Md5TestGroup, test10) {
    std::string expected = "439a0a7d4245cbb34dc1d8c87da30298";
    std::string actual = Md5::getMd5Hash(
            "ruNBid13 VvxnGB3B^lq4^LDTj 8dZ&n42-3Faz4tN~!@Ssb seHu@$Es,hHfNK)x(Jm?L%rT1bkjwfe+nDsi=1I/XPax%DnibuI");
    STRCMP_EQUAL(expected.data(), actual.data())
}