
void sh_remove_from_list_part_1(void)

{
  undefined4 in_r3;
  
                    /* WARNING: Subroutine does not return */
  OPENSSL_die("assertion failed: WITHIN_FREELIST(temp2->p_next) || WITHIN_ARENA(temp2->p_next)",
              "crypto/mem_sec.c",0x17a,in_r3,in_r3);
}

