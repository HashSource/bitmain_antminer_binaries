
/* WARNING: Unknown calling convention */

void set_TW_write_command_vil(uint *value)

{
  int iVar1;
  int iVar2;
  
  pthread_mutex_lock(DAT_0002e918);
  iVar2 = 1;
  iVar1 = *(int *)(DAT_0002e91c + 0x8d4);
  do {
    if (iVar2 == 1) {
      *(uint *)(iVar1 + 0x40) = *value;
    }
    else {
      *(uint *)(iVar1 + 0x44) = value[iVar2 + -1];
      if (iVar2 == 0xd) {
                    /* WARNING: Could not recover jumptable at 0x0000a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR_LAB_0005f228)(DAT_0002e918);
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

