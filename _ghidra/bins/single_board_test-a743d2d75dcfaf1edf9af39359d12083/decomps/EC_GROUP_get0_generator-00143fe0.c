
EC_POINT * EC_GROUP_get0_generator(EC_GROUP *group)

{
  return *(EC_POINT **)(group + 4);
}

