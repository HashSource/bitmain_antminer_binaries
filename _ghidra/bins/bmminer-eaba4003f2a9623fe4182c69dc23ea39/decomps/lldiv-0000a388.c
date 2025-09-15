
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lldiv_t * lldiv(lldiv_t *__return_storage_ptr__,longlong __numer,longlong __denom)

{
  lldiv_t *plVar1;
  undefined4 in_r1;
  
  plVar1 = (lldiv_t *)
           (*(code *)(undefined *)0x0)
                     (__return_storage_ptr__,in_r1,(int)__numer,(int)((ulonglong)__numer >> 0x20));
  return plVar1;
}

