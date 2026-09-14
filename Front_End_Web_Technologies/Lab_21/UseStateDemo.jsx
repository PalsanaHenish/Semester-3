import { useState } from 'react'

function UseStateDemo() {
    const [visible, setVisible] = useState(false);
    return (
        <>
            <center>
                <h1>useState() Demo</h1>
                {!visible && <button onClick={() => setVisible(true)}>Utsav</button>}
                {visible && <button onClick={() => setVisible(false)}>Dhairya</button>}
                {visible && <h1>Dhairya Makwana is a name of a Human which means PATIENCE</h1>}
                {!visible && <h1>Utsav kanzariya is a Highly Talented Entity</h1>}
            </center>
        </>
    )
}

export default UseStateDemo
