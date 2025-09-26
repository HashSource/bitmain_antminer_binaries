
char * OBJ_NAME_get(char *name,int type)

{
  void *pvVar1;
  uint local_20 [2];
  char *local_18;
  
  if (name != (char *)0x0) {
    if (names_lh == (_LHASH *)0x0) {
      CRYPTO_mem_ctrl(3);
      names_lh = lh_new((LHASH_HASH_FN_TYPE)0x1349a1,(LHASH_COMP_FN_TYPE)0x134961);
      CRYPTO_mem_ctrl(2);
      if (names_lh == (_LHASH *)0x0) {
        return (char *)0x0;
      }
    }
    local_20[0] = type & 0xffff7fff;
    local_18 = name;
    if (type << 0x10 < 0) {
      pvVar1 = lh_retrieve(names_lh,local_20);
      if (pvVar1 != (void *)0x0) goto LAB_00134c9a;
    }
    else {
      pvVar1 = lh_retrieve(names_lh,local_20);
      if (pvVar1 != (void *)0x0) {
        if (*(int *)((int)pvVar1 + 4) != 0) {
          local_18 = *(char **)((int)pvVar1 + 0xc);
          pvVar1 = lh_retrieve(names_lh,local_20);
          if (pvVar1 == (void *)0x0) {
            return (char *)0x0;
          }
          if (*(int *)((int)pvVar1 + 4) != 0) {
            local_18 = *(char **)((int)pvVar1 + 0xc);
            pvVar1 = lh_retrieve(names_lh,local_20);
            if (pvVar1 == (void *)0x0) {
              return (char *)0x0;
            }
            if (*(int *)((int)pvVar1 + 4) != 0) {
              local_18 = *(char **)((int)pvVar1 + 0xc);
              pvVar1 = lh_retrieve(names_lh,local_20);
              if (pvVar1 == (void *)0x0) {
                return (char *)0x0;
              }
              if (*(int *)((int)pvVar1 + 4) != 0) {
                local_18 = *(char **)((int)pvVar1 + 0xc);
                pvVar1 = lh_retrieve(names_lh,local_20);
                if (pvVar1 == (void *)0x0) {
                  return (char *)0x0;
                }
                if (*(int *)((int)pvVar1 + 4) != 0) {
                  local_18 = *(char **)((int)pvVar1 + 0xc);
                  pvVar1 = lh_retrieve(names_lh,local_20);
                  if (pvVar1 == (void *)0x0) {
                    return (char *)0x0;
                  }
                  if (*(int *)((int)pvVar1 + 4) != 0) {
                    local_18 = *(char **)((int)pvVar1 + 0xc);
                    pvVar1 = lh_retrieve(names_lh,local_20);
                    if (pvVar1 == (void *)0x0) {
                      return (char *)0x0;
                    }
                    if (*(int *)((int)pvVar1 + 4) != 0) {
                      local_18 = *(char **)((int)pvVar1 + 0xc);
                      pvVar1 = lh_retrieve(names_lh,local_20);
                      if (pvVar1 == (void *)0x0) {
                        return (char *)0x0;
                      }
                      if (*(int *)((int)pvVar1 + 4) != 0) {
                        local_18 = *(char **)((int)pvVar1 + 0xc);
                        pvVar1 = lh_retrieve(names_lh,local_20);
                        if (pvVar1 == (void *)0x0) {
                          return (char *)0x0;
                        }
                        if (*(int *)((int)pvVar1 + 4) != 0) {
                          local_18 = *(char **)((int)pvVar1 + 0xc);
                          pvVar1 = lh_retrieve(names_lh,local_20);
                          if (pvVar1 == (void *)0x0) {
                            return (char *)0x0;
                          }
                          if (*(int *)((int)pvVar1 + 4) != 0) {
                            local_18 = *(char **)((int)pvVar1 + 0xc);
                            pvVar1 = lh_retrieve(names_lh,local_20);
                            if (pvVar1 == (void *)0x0) {
                              return (char *)0x0;
                            }
                            if (*(int *)((int)pvVar1 + 4) != 0) {
                              return (char *)0x0;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
LAB_00134c9a:
        return *(char **)((int)pvVar1 + 0xc);
      }
    }
  }
  return (char *)0x0;
}

