import D from './D'

function C(props) {
    return (
        <div>
            Component C
            <D name={props.name} />
        </div>
    )
}

export default C
