use DBI;
use DBI qw(:sql_types);
package Data::testcase;
$dbh;
$sth;

sub connect
{
  my ($dsn, $u, $p) = @_;
  undef $dbh;
  $dbh = DBI->connect($dsn, $u, $p) || die "error connect: $DBI::errstr";
  return $dbh->ping;
}

sub disconnect
{
  my $r = 0;
  if (defined $dbh)
  {
    if (defined $sth)
    {
      $sth->finish;
      undef $sth;
    }
    $r = $dbh->disconnect or die $dbh->errstr;
    undef $dbh;
  }
  return $r;
}

sub do_ping
{
  die "Not connected" if !defined $dbh;

  return $dbh->ping;
}
