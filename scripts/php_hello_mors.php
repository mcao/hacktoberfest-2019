<?php
   if(isset($_POST['submit']) :
   
      echo("Hello " . $_POST['name'] . ", nice to meet you.");
 
   else: ?>
   <form action="" method="post">
     <p>Name: <input type="text" name="name" /></p>
     <input type="submit" name="submit" value="Submit" />
   </form>
   <?php endif;
