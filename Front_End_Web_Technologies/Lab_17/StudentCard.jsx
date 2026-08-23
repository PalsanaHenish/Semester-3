import React from 'react'

function StudentCard() {
    const students = [
        {
            name: "Priyanshi",
            branch: "B.Tech",
            enrollment: 24010101223,
            city: "Dhoraji",
            spi: 9.4,
        },
        {
            name: "Dhruvi",
            branch: "IT",
            enrollment: 24010101208,
            city: "Jetpur",
            spi: 8.6,
        },
        {
            name: "Diya",
            branch: "BBA",
            enrollment: 24010101115,
            city: "Rajkot",
            spi: 9.0,
        },
        {
            name: "Pari",
            branch: "BCA",
            enrollment: 24010101201,
            city: "Dhoraji",
            spi: 8.7,
        },
        {
            name: "Khushi",
            branch: "B.Com",
            enrollment: 24010101185,
            city: "Ahmdabad",
            spi: 8.9,
        },
    ];
    return (
        <>
            <table border={1} cellSpacing={0}>
                <thead>
                    <th>Name</th>
                    <th>Branch</th>
                    <th>Enrollment No.</th>
                    <th>City</th>
                    <th>SPI</th>
                </thead>
                <tbody>
                    {
                        students.map((f) => <tr>
                            <td>{f.name}</td>
                            <td>{f.branch}</td>
                            <td>{f.enrollment}</td>
                            <td>{f.city}</td>
                            <td>{f.spi}</td>
                        </tr>)
                    }
                </tbody>
            </table>
        </>
    )
}

export default StudentCard
