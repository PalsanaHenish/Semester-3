
function Dashbord({currentUser, handleLogOut}) {
  return (
    <>
      <h1>Dashboard</h1>
      <h2>Profile : {currentUser}</h2>
      <button onClick={handleLogOut}>Logout</button>
    </>
  )
}

export default Dashbord
