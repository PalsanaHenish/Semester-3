import React from 'react'

function FacultyTable() {
    const faculty = [
        {
            name: "Dr. John Smith",
            department: "Computer Science",
            position: "Professor",
            email: "john.smith@university.edu",
            phone: "123-456-7890"
        },
        {
            name: "Dr. Emily Johnson",
            department: "Mathematics",
            position: "Associate Professor",
            email: "emily.johnson@university.edu",
            phone: "234-567-8901"
        },
        {
            name: "Dr. Michael Brown",
            department: "Physics",
            position: "Assistant Professor",
            email: "michael.brown@university.edu",
            phone: "345-678-9012"
        },
        {
            name: "Dr. Sarah Davis",
            department: "Chemistry",
            position: "Lecturer",
            email: "sarah.davis@university.edu",
            phone: "456-789-0123"
        },
        {
            name: "Dr. Robert Wilson",
            department: "Biology",
            position: "Professor",
            email: "robert.wilson@university.edu",
            phone: "567-890-1234"
        },
        {
            name: "Dr. Laura Martinez",
            department: "English",
            position: "Assistant Professor",
            email: "laura.martinez@university.edu",
            phone: "678-901-2345"
        },
        {
            name: "Dr. James Taylor",
            department: "History",
            position: "Professor",
            email: "james.taylor@university.edu",
            phone: "789-012-3456"
        },
        {
            name: "Dr. Jennifer Anderson",
            department: "Philosophy",
            position: "Lecturer",
            email: "jennifer.anderson@university.edu",
            phone: "890-123-4567"
        },
        {
            name: "Dr. William Thomas",
            department: "Economics",
            position: "Associate Professor",
            email: "william.thomas@university.edu",
            phone: "901-234-5678"
        },
        {
            name: "Dr. Mary Jackson",
            department: "Sociology",
            position: "Professor",
            email: "mary.jackson@university.edu",
            phone: "012-345-6789"
        }
    ];

    return (
        <>
            <table border={1} cellSpacing={0}>
                <thead>
                    <th>Name</th>
                    <th>Department</th>
                    <th>Position</th>
                    <th>Email</th>
                    <th>Phone</th>
                </thead>
                <tbody>
                    {
                        faculty.map((f)=><tr>
                            <td>{f.name}</td>
                            <td>{f.department}</td>
                            <td>{f.position}</td>
                            <td>{f.email}</td>
                            <td>{f.phone}</td>
                        </tr>)
                    }
                </tbody>
            </table>
        </>
    )
}

export default FacultyTable
