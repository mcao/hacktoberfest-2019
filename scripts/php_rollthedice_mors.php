<?php

function roll($sides){
  return 'You rolled ' . mt_rand(1, $sides) . '!';
}

echo roll(20);
