
/* WARNING: Variable defined which should be unmapped: real-local */

json_t * json_real_copy(json_t *real)

{
  json_t *pjVar1;
  undefined4 uStack_10;
  json_t *real_local;
  
  json_real_value(real);
  pjVar1 = json_real((double)CONCAT44(real,uStack_10));
  return pjVar1;
}

