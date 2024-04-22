
/* WARNING: Variable defined which should be unmapped: integer-local */

json_t * json_integer_copy(json_t *integer)

{
  json_t *pjVar1;
  undefined4 uStack_10;
  json_t *integer_local;
  
  json_integer_value(integer);
  pjVar1 = json_integer(CONCAT44(integer,uStack_10));
  return pjVar1;
}

