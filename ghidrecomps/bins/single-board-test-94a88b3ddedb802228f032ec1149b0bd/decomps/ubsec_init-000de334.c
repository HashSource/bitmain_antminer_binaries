
undefined4 ubsec_init(void)

{
  char **ppcVar1;
  char **ppcVar2;
  char *pcVar3;
  DSO *dso;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  DSO_FUNC_TYPE pDVar6;
  DSO_FUNC_TYPE pDVar7;
  DSO_FUNC_TYPE pDVar8;
  DSO_FUNC_TYPE pDVar9;
  DSO_FUNC_TYPE pDVar10;
  DSO_FUNC_TYPE pDVar11;
  DSO_FUNC_TYPE pDVar12;
  DSO_FUNC_TYPE pDVar13;
  DSO_FUNC_TYPE pDVar14;
  DSO_FUNC_TYPE pDVar15;
  DSO_FUNC_TYPE pDVar16;
  int iVar17;
  int iVar18;
  
  ppcVar1 = DAT_000de508;
  if (DAT_000de508[2] == (char *)0x0) {
    pcVar3 = *DAT_000de508;
    if (*DAT_000de508 == (char *)0x0) {
      pcVar3 = DAT_000de510;
    }
    dso = DSO_load((DSO *)0x0,pcVar3,(DSO_METHOD *)0x0,0);
    ppcVar1[2] = (char *)dso;
    if (dso == (DSO *)0x0) {
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar1[1] = pcVar3;
      }
      iVar17 = 0x19e;
    }
    else {
      pDVar4 = DSO_bind_func(dso,DAT_000de514);
      if ((((((pDVar4 != (DSO_FUNC_TYPE)0x0) &&
             (pDVar5 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de518), pDVar5 != (DSO_FUNC_TYPE)0x0))
            && (pDVar6 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de51c), pDVar6 != (DSO_FUNC_TYPE)0x0
               )) && (((pDVar7 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de520),
                       pDVar7 != (DSO_FUNC_TYPE)0x0 &&
                       (pDVar8 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de524),
                       pDVar8 != (DSO_FUNC_TYPE)0x0)) &&
                      ((pDVar9 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de528),
                       pDVar9 != (DSO_FUNC_TYPE)0x0 &&
                       ((pDVar10 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de52c),
                        pDVar10 != (DSO_FUNC_TYPE)0x0 &&
                        (pDVar11 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de530),
                        pDVar11 != (DSO_FUNC_TYPE)0x0)))))))) &&
          (pDVar12 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de534), pDVar12 != (DSO_FUNC_TYPE)0x0))
         && ((((pDVar13 = DSO_bind_func((DSO *)ppcVar1[2],DAT_000de538), ppcVar2 = DAT_000de508,
               pDVar13 != (DSO_FUNC_TYPE)0x0 &&
               (pDVar14 = DSO_bind_func((DSO *)DAT_000de508[2],DAT_000de53c),
               pDVar14 != (DSO_FUNC_TYPE)0x0)) &&
              (pDVar15 = DSO_bind_func((DSO *)ppcVar2[2],DAT_000de540),
              pDVar15 != (DSO_FUNC_TYPE)0x0)) &&
             (pDVar16 = DSO_bind_func((DSO *)ppcVar2[2],DAT_000de544), pDVar16 != (DSO_FUNC_TYPE)0x0
             )))) {
        ppcVar2[3] = (char *)pDVar4;
        ppcVar2[4] = (char *)pDVar5;
        ppcVar2[5] = (char *)pDVar6;
        ppcVar2[9] = (char *)pDVar10;
        ppcVar2[6] = (char *)pDVar7;
        ppcVar2[7] = (char *)pDVar8;
        ppcVar2[10] = (char *)pDVar11;
        ppcVar2[8] = (char *)pDVar9;
        ppcVar2[0xb] = (char *)pDVar12;
        ppcVar2[0xc] = (char *)pDVar13;
        ppcVar2[0xe] = (char *)pDVar15;
        ppcVar2[0xf] = (char *)pDVar16;
        ppcVar2[0xd] = (char *)pDVar14;
        iVar17 = (*pDVar6)(DAT_000de548);
        if ((0 < iVar17) && (iVar18 = (*(code *)ppcVar2[0xf])(iVar17,DAT_000de54c), iVar18 == 0)) {
          (*(code *)ppcVar2[6])(iVar17);
          return 1;
        }
        ppcVar2 = DAT_000de508;
        pcVar3 = ppcVar1[1];
        if (pcVar3 == (char *)0x0) {
          pcVar3 = (char *)ERR_get_next_error_library();
          ppcVar2[1] = pcVar3;
        }
        ERR_put_error((int)pcVar3,0x69,0x6c,DAT_000de50c,0x1e1);
        goto LAB_000de358;
      }
      ppcVar2 = DAT_000de508;
      pcVar3 = ppcVar1[1];
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)ERR_get_next_error_library();
        ppcVar2[1] = pcVar3;
      }
      iVar17 = 0x1c2;
    }
    ERR_put_error((int)pcVar3,0x69,0x67,DAT_000de50c,iVar17);
  }
  else {
    pcVar3 = DAT_000de508[1];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)ERR_get_next_error_library();
      ppcVar1[1] = pcVar3;
    }
    ERR_put_error((int)pcVar3,0x69,100,DAT_000de50c,0x196);
  }
LAB_000de358:
  if ((DSO *)ppcVar1[2] != (DSO *)0x0) {
    DSO_free((DSO *)ppcVar1[2]);
  }
  ppcVar1[2] = (char *)0x0;
  ppcVar1[3] = (char *)0x0;
  ppcVar1[4] = (char *)0x0;
  ppcVar1[5] = (char *)0x0;
  ppcVar1[6] = (char *)0x0;
  ppcVar1[7] = (char *)0x0;
  ppcVar1[8] = (char *)0x0;
  ppcVar1[9] = (char *)0x0;
  ppcVar1[10] = (char *)0x0;
  ppcVar1[0xb] = (char *)0x0;
  ppcVar1[0xc] = (char *)0x0;
  ppcVar1[0xd] = (char *)0x0;
  ppcVar1[0xe] = (char *)0x0;
  ppcVar1[0xf] = (char *)0x0;
  return 0;
}

