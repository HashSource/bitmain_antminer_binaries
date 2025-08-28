
/* WARNING: Unknown calling convention */

char * first_opt(uint *i,uint *len)

{
  char cVar1;
  opt_table *poVar2;
  opt_table *poVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  opt_table *poVar7;
  bool bVar8;
  
  *i = 0;
  if (opt_count == 0) {
LAB_0003ae22:
    pcVar4 = (char *)0x0;
  }
  else {
    poVar7 = opt_table;
    if (opt_table->type == OPT_SUBTABLE) {
      uVar5 = 1;
      poVar2 = opt_table;
      do {
        poVar7 = poVar2 + 1;
        *i = uVar5;
        if (opt_count <= uVar5) goto LAB_0003ae22;
        poVar3 = poVar2 + 1;
        uVar5 = uVar5 + 1;
        poVar2 = poVar7;
      } while (poVar3->type == OPT_SUBTABLE);
    }
    pcVar4 = poVar7->names;
    uVar5 = (uint)(byte)pcVar4[1];
    if (uVar5 != 0) {
      if ((uVar5 == 0x7c) || (uVar5 == 0x3d)) {
        uVar5 = 0;
      }
      else {
        bVar8 = uVar5 != 0x20;
        uVar5 = 0;
        uVar6 = uVar5;
        if (bVar8) {
          do {
            uVar5 = uVar6 + 1;
            cVar1 = pcVar4[uVar6 + 2];
            if (((cVar1 == '\0') || (cVar1 == '|')) || (cVar1 == '=')) break;
            uVar6 = uVar5;
          } while (cVar1 != ' ');
        }
      }
    }
    pcVar4 = pcVar4 + 1;
    *len = uVar5;
  }
  return pcVar4;
}

