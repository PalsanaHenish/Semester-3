import B from './B'
import { useState } from 'react'

function A2() {
    const [name, setName] = useState("");
    return (
        <div>
            Component A
            <B name={name} setName={setName} />
        </div>
    )
}

export default A2