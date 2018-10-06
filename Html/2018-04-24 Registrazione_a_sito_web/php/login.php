<?php
if (isset($_POST["username"])&&isset($_POST["password"])) {
	$username = $_POST['username'];
	$password = $_POST['password'];

	// connessione al database
	require "connect.php";

//$sqlLogin = "SELECT * FROM phptest.utenti WHERE username = '{$username}' AND password = '{$username}'";
	$sqlLogin = "SELECT * FROM phptest.utenti WHERE username = '".$username."' AND password = '".$password."'";	
	$connect->query($insertRecord);
}
	echo "success";

/*
class Users {
	public $username = null;
	public $password = null;

	public function __construct( $data = array() ) {
	   if( isset( $data['username'] ) ) $this->username = stripslashes( strip_tags( $data['username'] ) );
	   if( isset( $data['password'] ) ) $this->password = stripslashes( strip_tags( $data['password'] ) );
	}

	public function storeFormValues( $params ) {
	  $this->__construct( $params ); 
	}

	public function Login() {
		$success = false;
		define( "DB_DSN", "mssql:host=localhost;dbname=phptest" );
		define( "DB_USERNAME", "root" );
		define( "DB_PASSWORD", "" );
		try{
/*		require "../connect.php";
	   	$query = "SELECT username,password 
			FROM phptest.utenti 
			WHERE utenti.username LIKE '".$username."' AND
			utenti.password LIKE '".$password."'";
			$result = mysqli_query($connect, $query);
*/
/*
      $con = new PDO( DB_DSN, DB_USERNAME, DB_PASSWORD ); 
      $con->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
      $sql = "SELECT * FROM utenti WHERE username = :username AND password = :password LIMIT 1";
      $user = username;

      $stmt = $con->prepare( $sql );
      $stmt->bindValue( "username", $this->username, PDO::PARAM_STR );
      $stmt->bindValue( "password", md5($this->password), PDO::PARAM_STR );
      $stmt->execute();

      $valid = $stmt->fetchColumn();

      if( $valid ) {
	      $success = true;
	      session_start();
	      session_regenerate_id();
	      $_SESSION['user'] = $user['user'];
	      session_write_close();
	      echo ('Login');
	      exit();
      }
      $con = null;
      return $success;
    } catch (PDOException $e) {
      echo $e->getMessage();
      return $success;
		}
	}
}


/*
			if (mysqli_num_rows($result) > 0) {
				echo "<h1 align='center' style='background-color:#cfffcc;'>Hai fatto il login ".$username."!</h1>";
			  $user = username;				
				$success = true;
				session_start();

				session_regenerate_id();
				$_SESSION['user'] = $user['user'];
				session_write_close();
				echo ('Login');
				exit();
			} else {
				echo "<h1 align='center' style='background-color:#ffcccc;'>Username o password sbagliati</h1>";
			}	return $success;
		} catch (PDOException $e) {
	    echo $e->getMessage();
	    return $success;
		}


/*
class Users {
	public $username = null;
	public $password = null;

	public function __construct( $data = array() ) {
	   if( isset( $data['username'] ) ) $this->username = stripslashes( strip_tags( $data['username'] ) );
	   if( isset( $data['password'] ) ) $this->password = stripslashes( strip_tags( $data['password'] ) );
	}

	public function storeFormValues( $params ) {
	  $this->__construct( $params ); 
	}

	public function Login() {
	   $success = false;
	   try{
	      $con = new PDO( DB_DSN, DB_USERNAME, DB_PASSWORD ); 
	      $con->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
	      $sql = "SELECT * FROM users WHERE username = :username AND password = :password LIMIT 1";
	                  $user = username;

	      $stmt = $con->prepare( $sql );
	      $stmt->bindValue( "username", $this->username, PDO::PARAM_STR );
	      $stmt->bindValue( "password", md5($this->password), PDO::PARAM_STR );
	      $stmt->execute();

	      $valid = $stmt->fetchColumn();

	      if( $valid ) {
	      $success = true;
	                  session_start();


	      session_regenerate_id();
	      $_SESSION['user'] = $user['user'];
	      session_write_close();
	      echo ('Login');
	      exit();

	      }

	      $con = null;
	      return $success;
	      }catch (PDOException $e) {
	      echo $e->getMessage();
	      return $success;
	   }

	}
*/
?>