import { useEffect, useState } from 'react'

function UseEffectDemo() {
    const [ms, setms] = useState(0);

    useEffect(() => {setTimeout(() => {setms(ms + 1)},1000)}, [ms]);   

  return (
    <>
        <center style={{marginTop:100}}>
            <h1>useEffect() Demo</h1>
            <h2>Seconds : {ms}</h2>
        </center>
    </>
  )
}

export default UseEffectDemo
