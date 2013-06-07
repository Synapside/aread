<?php 
$page = "- Aread";
include('header.php');
?>

<div id = "content">
Aread calculates the area of a <i> regular </i> polygon only. That means that the polygon must have sides of equal length.<p>
<form id="aread" action=" " method="POST">
What information do you have? <p> 
<div id="radios">
<input type="radio" value="apothem" name="info" class="radio"> Apothem <br>
<input type="radio" value="radius" name="info" class="radio"> Radius <br>
<input type="radio" value="sidelength" name="info" class="radio"> Side Length <br>
</div>
</p>
<p>
Type in it's value below: <p>
<input type="text" name="number"> <br>
</p>
<p>
How many sides does the polygon have?<p>
<input type="text" name="sides"> <br>
</p>
<input type="submit" class="button" value="Calculate">
</form>

<?php
define("PI", "3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611");
if(isset($_POST['info'])) {
$info = $_POST['info'];
$sides = $_POST['sides'];
$radians = PI / $sides;
$tanr = tan($radians);
$cosr = cos($radians);
$sinr = sin($radians);
$area;

if (strstr($info, "apothem")) {
    $apothem = $_POST['number'];
    $sidelen = 2 * $tanr * $apothem;
    $area = $sidelen * .5 * $apothem * $sides;
}
else if (strstr($info, "radius")) {
    $radius = $_POST['number'];
    $sidelen = $radius * 2 * $sinr;
    $apothem = $radius * $cosr;
    $area = .5 * $sidelen * $apothem * $sides;
}
else if (strstr($info, "sidelength")) {
    $sidelen = $_POST['number'];
    $top = $sidelen * $sidelen * $sides;
    $bottom = $tanr * 4;
    $area = $top / $bottom;
}
else {
    echo "<p>There was an error. <br>";
    exit();
}

echo "<div id='result'> The area is $area. </div><br>";
}
?>
<?php
include "footer.php";
?>

