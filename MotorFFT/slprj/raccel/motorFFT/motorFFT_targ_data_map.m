  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 48;
      section.data(48)  = dumData; %prealloc
      
	  ;% rtP.fromWS_Signal1_Time0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.fromWS_Signal1_Data0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1178;
	
	  ;% rtP.FromWorkspace_Time0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2356;
	
	  ;% rtP.FromWorkspace_Data0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3534;
	
	  ;% rtP.FromWorkspace1_Time0
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4712;
	
	  ;% rtP.FromWorkspace1_Data0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5890;
	
	  ;% rtP.fromWS_Signal1_Time0_ndx3dzmkku
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7068;
	
	  ;% rtP.fromWS_Signal1_Data0_oas1myuoe3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8246;
	
	  ;% rtP.FromWorkspace_Time0_evtpn2dlvi
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9424;
	
	  ;% rtP.FromWorkspace_Data0_bw10wgblqr
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10602;
	
	  ;% rtP.FromWorkspace1_Time0_gvxb44qtwu
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11780;
	
	  ;% rtP.FromWorkspace1_Data0_f5g0ewuzoj
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12958;
	
	  ;% rtP.fromWS_Signal1_Time0_dv1n1hreha
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14136;
	
	  ;% rtP.fromWS_Signal1_Data0_baihte5jff
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15306;
	
	  ;% rtP.FromWorkspace_Time0_b0ruuf1opz
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16476;
	
	  ;% rtP.FromWorkspace_Data0_pcaxh4qntv
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17646;
	
	  ;% rtP.FromWorkspace1_Time0_evphbwmxwa
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18816;
	
	  ;% rtP.FromWorkspace1_Data0_ajxnvg3fs4
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19986;
	
	  ;% rtP.fromWS_Signal1_Time0_ld4ysq5re5
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21156;
	
	  ;% rtP.fromWS_Signal1_Data0_nmlefzf2qh
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22326;
	
	  ;% rtP.FromWorkspace_Time0_mylv0l5y5l
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23496;
	
	  ;% rtP.FromWorkspace_Data0_ii4u0weofd
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24666;
	
	  ;% rtP.FromWorkspace1_Time0_jq4gg3fl1c
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25836;
	
	  ;% rtP.FromWorkspace1_Data0_delfmtqm10
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27006;
	
	  ;% rtP.fromWS_Signal1_Time0_knw2zejkhf
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28176;
	
	  ;% rtP.fromWS_Signal1_Data0_dqatlaamxd
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29345;
	
	  ;% rtP.FromWorkspace_Time0_ey3pumuhzx
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30514;
	
	  ;% rtP.FromWorkspace_Data0_dhfho4iunp
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31683;
	
	  ;% rtP.FromWorkspace1_Time0_nswp0gh53d
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32852;
	
	  ;% rtP.FromWorkspace1_Data0_cws5e25kve
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 34021;
	
	  ;% rtP.fromWS_Signal1_Time0_jf1ovizl0b
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 35190;
	
	  ;% rtP.fromWS_Signal1_Data0_bmzttyl35q
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 36359;
	
	  ;% rtP.FromWorkspace_Time0_inageeqpai
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 37528;
	
	  ;% rtP.FromWorkspace_Data0_kzvsc32h2c
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 38697;
	
	  ;% rtP.FromWorkspace1_Time0_hsp0vfmomf
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 39866;
	
	  ;% rtP.FromWorkspace1_Data0_afourxrbaa
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 41035;
	
	  ;% rtP.fromWS_Signal1_Time0_izyjwzvjth
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 42204;
	
	  ;% rtP.fromWS_Signal1_Data0_dnuljhqvk4
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 43402;
	
	  ;% rtP.FromWorkspace_Time0_atfy3pm4jv
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 44600;
	
	  ;% rtP.FromWorkspace_Data0_l3lbhy1g0h
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 45798;
	
	  ;% rtP.FromWorkspace1_Time0_drehnj2kvb
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 46996;
	
	  ;% rtP.FromWorkspace1_Data0_k4fehecuxx
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 48194;
	
	  ;% rtP.fromWS_Signal1_Time0_fpgnvffwdi
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 49392;
	
	  ;% rtP.fromWS_Signal1_Data0_hc01az2ko0
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 50590;
	
	  ;% rtP.FromWorkspace_Time0_j4qtllopkd
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 51788;
	
	  ;% rtP.FromWorkspace_Data0_kkea1guu30
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 52986;
	
	  ;% rtP.FromWorkspace1_Time0_gpsy5fvy5d
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 54184;
	
	  ;% rtP.FromWorkspace1_Data0_gcmrjxmyv0
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 55382;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% rtB.gregxvrhdq
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.iey5yp5yc3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.ah0n04lkk0
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.adgfg4spum
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.hsn4any1yz
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.ez1dpie4tk
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.ip0uvrp3z3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.lzl45qjifg
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.fvz5ztlupg
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.jappjfmhaf
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.hzs2cffwsh
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.mqr2iftmcf
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.bv141smffr
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.n0ofmubc1v
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.hkzej0bbqv
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.hyn4m540so
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtB.i5xm4g4u24
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtB.gmacchlgce
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtB.phph3pe0fd
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtB.psxmxvyoop
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtB.jkpzefwce0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtB.atrkvlif4k
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtB.ekcsmuhkax
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtB.cwbebu3rd3
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% rtDW.azqf3zai0t.TimePtr
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jnemuuzgzp.TimePtr
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.pzvgpjidp0.TimePtr
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.fsvvqr0mni.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.j21ldtcnma.TimePtr
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtDW.a2z3xgtwiy.TimePtr
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtDW.oj2hmay041.TimePtr
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtDW.hk3des0jg0.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtDW.mmlzbnupg4.TimePtr
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% rtDW.l1aaxv0qvs.TimePtr
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% rtDW.h234jcxu2z.TimePtr
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% rtDW.clrd32dre4.LoggedData
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtDW.epftsymyqn.TimePtr
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% rtDW.ilpn10ybkm.TimePtr
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% rtDW.izkwmahydg.TimePtr
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% rtDW.okrhfkq4wg.LoggedData
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% rtDW.azgdj10ofq.TimePtr
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% rtDW.i1szh3fwfk.TimePtr
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% rtDW.iuvswjitkf.TimePtr
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 26;
	
	  ;% rtDW.aciovtayfr.LoggedData
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 27;
	
	  ;% rtDW.ayhphwsgwq.TimePtr
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% rtDW.ajdss4dhe0.TimePtr
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% rtDW.dh3f02y2sz.TimePtr
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 32;
	
	  ;% rtDW.msjdgqazw2.LoggedData
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 33;
	
	  ;% rtDW.kqoyc1etwg.TimePtr
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 36;
	
	  ;% rtDW.mvcdlyri2j.TimePtr
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 37;
	
	  ;% rtDW.hbcms1bq4r.TimePtr
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 38;
	
	  ;% rtDW.imhpm3odyo.LoggedData
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 39;
	
	  ;% rtDW.ddvlfm2hus.TimePtr
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 42;
	
	  ;% rtDW.l3wkq1xedj.TimePtr
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 43;
	
	  ;% rtDW.pjjr10dg4b.TimePtr
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 44;
	
	  ;% rtDW.ekwpduodoq.LoggedData
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% rtDW.i3mtw4xzzf.PrevIndex
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.pfd1w3cfyn.PrevIndex
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.b5nhs0lacr.PrevIndex
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.irfywsshjv.PrevIndex
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.mjelp1v40r.PrevIndex
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.gzrsy1zuao.PrevIndex
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.jsowmhyjmc.PrevIndex
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.px2wccwv40.PrevIndex
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.giadlp5izi.PrevIndex
	  section.data(9).logicalSrcIdx = 40;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.nlmnijzpxw.PrevIndex
	  section.data(10).logicalSrcIdx = 41;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.poz2ms4ply.PrevIndex
	  section.data(11).logicalSrcIdx = 42;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.mz45s0obsk.PrevIndex
	  section.data(12).logicalSrcIdx = 43;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.ffaasee41y.PrevIndex
	  section.data(13).logicalSrcIdx = 44;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.mxgci4hatn.PrevIndex
	  section.data(14).logicalSrcIdx = 45;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.jfxavml4ss.PrevIndex
	  section.data(15).logicalSrcIdx = 46;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.emklnm5eee.PrevIndex
	  section.data(16).logicalSrcIdx = 47;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDW.j1ehnbr3p0.PrevIndex
	  section.data(17).logicalSrcIdx = 48;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDW.azpkt4wjbr.PrevIndex
	  section.data(18).logicalSrcIdx = 49;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDW.hhpqhvbomw.PrevIndex
	  section.data(19).logicalSrcIdx = 50;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDW.kp31dep3dx.PrevIndex
	  section.data(20).logicalSrcIdx = 51;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDW.pcfosdoawh.PrevIndex
	  section.data(21).logicalSrcIdx = 52;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDW.ir4ldnp24c.PrevIndex
	  section.data(22).logicalSrcIdx = 53;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDW.kxnor0qurr.PrevIndex
	  section.data(23).logicalSrcIdx = 54;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDW.nq5bs3wkyw.PrevIndex
	  section.data(24).logicalSrcIdx = 55;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1039835684;
  targMap.checksum1 = 1442330462;
  targMap.checksum2 = 3807622218;
  targMap.checksum3 = 3995259496;

