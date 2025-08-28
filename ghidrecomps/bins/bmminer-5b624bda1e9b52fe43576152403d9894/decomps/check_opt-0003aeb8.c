
/* WARNING: Unknown calling convention */

void check_opt(opt_table *entry)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  opt_type oVar4;
  anon_union_4_3_d8f38084_for_u aVar5;
  char *pcVar6;
  _func_char_ptr_void_ptr *p_Var7;
  uint uVar8;
  uint extraout_r3;
  uint extraout_r3_00;
  _func_char_ptr_char_ptr_void_ptr *p_Var9;
  opt_table *poVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  undefined8 uVar14;
  uint local_24 [2];
  
  oVar4 = entry->type;
  uVar8 = oVar4 - OPT_NOARG;
  bVar13 = (OPT_HASARG|OPT_NOARG) < oVar4;
  bVar11 = oVar4 == OPT_PROCESSARG;
  if (!bVar11) {
    bVar13 = uVar8 != 0;
  }
  bVar12 = uVar8 != 1;
  if (!bVar13 || (bVar11 || !bVar12)) {
    uVar8 = 0;
  }
  if (bVar13 && (!bVar11 && bVar12)) {
    uVar8 = 1;
  }
  if (bVar13 && (!bVar11 && bVar12)) {
LAB_0003af98:
    errx(1,"Option %s: unknown entry type %u",entry->names,oVar4);
  }
  else {
    if (entry->desc == (char *)0x0) goto LAB_0003afac;
    pcVar6 = entry->names;
    if (*pcVar6 == '-') {
      cVar3 = pcVar6[1];
      if (cVar3 == '\0') {
        local_24[0] = 0;
      }
      else {
        do {
          local_24[0] = uVar8;
          if (((cVar3 == '|') || (cVar3 == '=')) || (cVar3 == ' ')) break;
          local_24[0] = uVar8 + 1;
          cVar3 = pcVar6[uVar8 + 2];
          uVar8 = local_24[0];
        } while (cVar3 != '\0');
      }
      pcVar6 = pcVar6 + 1;
      while (*pcVar6 == '-') {
        uVar8 = local_24[0];
        if (local_24[0] == 1) goto LAB_0003af8e;
        oVar4 = entry->type;
        opt_num_long = opt_num_long + 1;
LAB_0003af34:
        if ((oVar4 == OPT_NOARG) &&
           (uVar1 = 1, uVar8 = local_24[0], pcVar6[local_24[0]] == ' ' || pcVar6[local_24[0]] == '='
           )) goto LAB_0003af82;
        pcVar6 = next_name(pcVar6,local_24);
        if (pcVar6 == (char *)0x0) {
          return;
        }
      }
      if (local_24[0] == 1) {
        oVar4 = entry->type;
        opt_num_short = opt_num_short + 1;
        if (oVar4 == OPT_HASARG || oVar4 == OPT_PROCESSARG) {
          opt_num_short_arg = opt_num_short_arg + 1;
        }
        goto LAB_0003af34;
      }
      pcVar6 = pcVar6 + -1;
      uVar1 = errx(1,"Option %s: invalid short option \'%.*s\'",entry->names,local_24[0] + 1,pcVar6)
      ;
      uVar8 = extraout_r3;
LAB_0003af82:
      errx(uVar1,"Option %s: does not take arguments \'%s\'",entry->names,pcVar6 + uVar8 + 1);
      uVar8 = extraout_r3_00;
LAB_0003af8e:
      uVar14 = errx(uVar8,"Option %s: invalid long option \'--\'",entry->names);
      oVar4 = (opt_type)((ulonglong)uVar14 >> 0x20);
      entry = (opt_table *)uVar14;
      goto LAB_0003af98;
    }
  }
  entry = (opt_table *)errx(1,"Option %s: does not begin with \'-\'");
LAB_0003afac:
  puVar2 = (undefined4 *)errx(1,"Option %s: description cannot be NULL",entry->names);
  opt_table = (opt_table *)realloc(opt_table,(opt_count + 1) * 0x1c);
  oVar4 = puVar2[1];
  p_Var7 = (_func_char_ptr_void_ptr *)puVar2[2];
  p_Var9 = (_func_char_ptr_char_ptr_void_ptr *)puVar2[3];
  poVar10 = opt_table + opt_count;
  poVar10->names = (char *)*puVar2;
  poVar10->type = oVar4;
  poVar10->cb = p_Var7;
  poVar10->cb_arg = p_Var9;
  aVar5 = *(anon_union_4_3_d8f38084_for_u *)(puVar2 + 5);
  pcVar6 = (char *)puVar2[6];
  opt_count = opt_count + 1;
  poVar10->show = (_func_void_char_ptr_void_ptr *)puVar2[4];
  poVar10->u = aVar5;
  poVar10->desc = pcVar6;
  return;
}

