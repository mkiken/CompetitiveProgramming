@args = split(/ /, <STDIN>);
($n, $time) = @args;
@p = split(/ /, <STDIN>);
@s = (); #Perlは動的配列
for($i = 0; $i < $n; $i++){
	my @ary = split(/ /, <STDIN>); #myでローカル変数にしないとリファレンスなので駄目
	$s[$i] = \@ary; #$s[$i] = @aryでは配列長が入ってしまうので駄目！！
}
@t = ();
for($i = 0; $i < $n; $i++){
	my @ary = split(/ /, <STDIN>);
	$t[$i] = \@ary;
}
@event = ();
$index = 0;
for($i = 0; $i < $n; $i++){
	for($j = 0; $j < $p[$i]; $j++){
		my @ary = ($s[$i][$j] + 0, $t[$i][$j] + 0, $i); # '+ 0' でstringをintに無理やり変換しておく

		$event[$index] = \@ary;
		$index++;
	}
}
#sort
@event2 = sort { $a->[0] <=> $b->[0]} @event; #$a[0]<=>$b[0]では駄目
#@event2 = sort { @$a[0] <=> @$b[0]} @event; #これでもOK
@point = ();
for($i = 0; $i < $n; $i++){
	$point[$i] = 0;
}
#event-drive
for($i = 0; $i < $index; $i++){
	my $ss = $event2[$i][0];
	my $tt = $event2[$i][1];
	my $ii = $event2[$i][2];

	if($time >= $tt){
		$time -= $tt;
		$point[$ii] = $ss;
	}
	else{
		last;
	}
}
#calculate ans
$ans = 0;
for($i = 0; $i < $n; $i++){
	$ans += $point[$i];
}
print $ans, "\n";
