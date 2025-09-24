
void sh_add_to_list(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar1 = DAT_00a27fcc;
  if ((param_1 < DAT_00a27fd4) || (DAT_00a27fd4 + DAT_00a27fd8 <= param_1)) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: WITHIN_FREELIST(list)","crypto/mem_sec.c",0x15e);
  }
  if ((DAT_00a27fcc <= param_2) &&
     (puVar3 = (uint *)(DAT_00a27fd0 + (int)DAT_00a27fcc), param_2 < puVar3)) {
    puVar2 = (uint *)*param_1;
    *param_2 = (uint)puVar2;
    if (puVar2 == (uint *)0x0) {
      param_2[1] = (uint)param_1;
      *param_1 = (uint)param_2;
      return;
    }
    if (puVar3 <= puVar2 || puVar2 < puVar1) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: temp->next == NULL || WITHIN_ARENA(temp->next)",
                  "crypto/mem_sec.c",0x163);
    }
    param_2[1] = (uint)param_1;
    if (param_1 != (uint *)puVar2[1]) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: (char **)temp->next->p_next == list","crypto/mem_sec.c",0x167);
    }
    puVar2[1] = (uint)param_2;
    *param_1 = (uint)param_2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: WITHIN_ARENA(ptr)","crypto/mem_sec.c",0x15f);
}

