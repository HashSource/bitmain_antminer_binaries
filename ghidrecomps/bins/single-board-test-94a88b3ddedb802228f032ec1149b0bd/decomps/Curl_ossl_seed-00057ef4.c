
void Curl_ossl_seed(int param_1)

{
  char *pcVar1;
  char *file;
  int iVar2;
  double in_stack_ffffffb0;
  
  pcVar1 = DAT_00057fa8;
  if (((*DAT_00057fa8 != '\0') && (*(int *)(param_1 + 0x3a4) == 0)) &&
     (*(int *)(param_1 + 0x3a0) == 0)) {
    return;
  }
  if (*(int *)(param_1 + 0x29c) != 0) {
    file = *(char **)(param_1 + 0x3a4);
    if (*(char **)(param_1 + 0x3a4) == (char *)0x0) {
      file = DAT_00057fac;
    }
    RAND_load_file(file,0x400);
    iVar2 = RAND_status();
    if (iVar2 != 0) goto LAB_00057f8a;
  }
  if (((*(char **)(param_1 + 0x3a0) == (char *)0x0) ||
      (iVar2 = RAND_egd(*(char **)(param_1 + 0x3a0)), iVar2 == -1)) ||
     (iVar2 = RAND_status(), iVar2 == 0)) {
    do {
      RAND_bytes(&stack0xffffffb0,0x40);
      RAND_add(&stack0xffffffb0,0x40,in_stack_ffffffb0);
      iVar2 = RAND_status();
    } while (iVar2 == 0);
    *(undefined *)(param_1 + 0x59c) = 0;
    RAND_file_name((char *)(param_1 + 0x59c),0x4000);
    if (*(char *)(param_1 + 0x59c) != '\0') {
      RAND_load_file((char *)(param_1 + 0x59c),0x400);
      iVar2 = RAND_status();
      if (iVar2 != 0) goto LAB_00057f8a;
    }
    Curl_infof(param_1,DAT_00057fb0);
  }
LAB_00057f8a:
  *pcVar1 = '\x01';
  return;
}

