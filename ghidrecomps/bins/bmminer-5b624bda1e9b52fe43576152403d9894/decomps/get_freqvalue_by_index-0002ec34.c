
/* WARNING: Unknown calling convention */

int get_freqvalue_by_index(int index)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a3d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0005f27c)(freq_pll_1385[index].freq,0,10);
  return iVar1;
}

