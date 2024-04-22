
/* WARNING: Unknown calling convention */

void check_opt(opt_table *entry)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  opt_table *poVar5;
  opt_table *poVar6;
  undefined4 uVar7;
  char **ppcVar8;
  char cVar9;
  opt_type oVar10;
  anon_union_4_3_d8f38084_for_u aVar11;
  char *pcVar12;
  _func_char_ptr_void_ptr *p_Var13;
  undefined *puVar14;
  _func_char_ptr_char_ptr_void_ptr *p_Var15;
  char *p;
  opt_table *names;
  bool bVar16;
  bool bVar17;
  undefined *local_24 [2];
  
  piVar4 = DAT_0003afd8;
  piVar3 = DAT_0003afd4;
  piVar2 = DAT_0003afb8;
  oVar10 = entry->type;
  puVar14 = (undefined *)(oVar10 + 0xffffffff);
  bVar17 = (OPT_NOARG|OPT_HASARG) < oVar10;
  bVar16 = oVar10 == OPT_PROCESSARG;
  if (!bVar16) {
    bVar17 = puVar14 != (undefined *)0x0;
  }
  bVar1 = puVar14 != (undefined *)0x1;
  if (!bVar17 || (bVar16 || !bVar1)) {
    puVar14 = (undefined *)0x0;
  }
  if (bVar17 && (!bVar16 && bVar1)) {
    puVar14 = (undefined *)0x1;
  }
  if (bVar17 && (!bVar16 && bVar1)) {
LAB_0003af98:
    errx(1,DAT_0003afc8,entry->names);
  }
  else {
    if (entry->desc == (char *)0x0) goto LAB_0003afac;
    pcVar12 = entry->names;
    if (*pcVar12 == '-') {
      cVar9 = pcVar12[1];
      if (cVar9 == '\0') {
        puVar14 = (undefined *)0x0;
      }
      else {
        do {
          if (((cVar9 == '|') || (cVar9 == '=')) || (cVar9 == ' ')) break;
          puVar14 = puVar14 + 1;
          cVar9 = (pcVar12 + (int)puVar14)[1];
        } while (cVar9 != '\0');
      }
      poVar5 = entry;
      names = (opt_table *)(pcVar12 + 1);
      local_24[0] = puVar14;
      while (*(char *)&names->names != '-') {
        if (local_24[0] != (undefined *)0x1) {
          names = (opt_table *)((int)&names[-1].desc + 3);
          puVar14 = local_24[0] + 1;
          uVar7 = errx(1,DAT_0003afbc,entry->names,puVar14,names);
LAB_0003af82:
          puVar14 = puVar14 + 1 + (int)&names->names;
          errx(uVar7,DAT_0003afc0,entry->names,puVar14);
          goto LAB_0003af8e;
        }
        poVar6 = (opt_table *)entry->type;
        if (poVar6 == (opt_table *)0x2 || poVar6 == (opt_table *)0x4) {
          poVar5 = poVar6;
        }
        *piVar3 = *piVar3 + 1;
        if (poVar6 == (opt_table *)0x2 || poVar6 == (opt_table *)0x4) {
          *piVar2 = *piVar2 + 1;
          poVar6 = poVar5;
        }
LAB_0003af34:
        if ((poVar6 == (opt_table *)0x1) &&
           (uVar7 = 1, puVar14 = local_24[0],
           local_24[0][(int)&names->names] == ' ' || local_24[0][(int)&names->names] == '='))
        goto LAB_0003af82;
        poVar5 = (opt_table *)next_name((char *)names,(uint *)local_24);
        names = poVar5;
        if (poVar5 == (opt_table *)0x0) {
          return;
        }
      }
      puVar14 = local_24[0];
      if (local_24[0] != (undefined *)0x1) {
        poVar6 = (opt_table *)entry->type;
        *piVar4 = *piVar4 + 1;
        goto LAB_0003af34;
      }
LAB_0003af8e:
      entry = (opt_table *)errx(puVar14,DAT_0003afc4,entry->names);
      goto LAB_0003af98;
    }
  }
  entry = (opt_table *)errx(1,DAT_0003afcc);
LAB_0003afac:
  ppcVar8 = (char **)errx(1,DAT_0003afd0,entry->names);
  opt_table = (opt_table *)realloc(opt_table,(opt_count + 1) * 0x1c);
  pcVar12 = ppcVar8[1];
  p_Var13 = (_func_char_ptr_void_ptr *)ppcVar8[2];
  p_Var15 = (_func_char_ptr_char_ptr_void_ptr *)ppcVar8[3];
  poVar5 = opt_table + opt_count;
  poVar5->names = *ppcVar8;
  poVar5->type = (opt_type)pcVar12;
  poVar5->cb = p_Var13;
  poVar5->cb_arg = p_Var15;
  aVar11 = *(anon_union_4_3_d8f38084_for_u *)(ppcVar8 + 5);
  pcVar12 = ppcVar8[6];
  opt_count = opt_count + 1;
  poVar5->show = (_func_void_char_ptr_void_ptr *)ppcVar8[4];
  poVar5->u = aVar11;
  poVar5->desc = pcVar12;
  return;
}

